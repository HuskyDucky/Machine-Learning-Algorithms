/**
    File    : Neural_Network.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.25            Version: 20190327.2

    Neural_Network

    Copyright (c) 2019 HuskyDucky (Menashe Rosemberg) rosemberg@ymail.com

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer in the documentation
       and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/
#include "Neural_Network.h"

Neural_Network::Neural_Network(const vector<uint16_t> layers,
                               const double LearnRate,
                               const AxonActFunction& fAxon) {
    const auto QOfLayers = layers.size();

    if (QOfLayers < 3) ABORT::BecauseOf(WRONG::QUANTITYofLAYERS);

    this->SynapsesLayers.reserve(QOfLayers);                ///Create Layers of synapses and all block of synapses has its Neurons

    this->SynapsesLayers.emplace_back(layers[0]);           //It doesn't have real neurons and just transfer the data to next layer
    for (uint8_t Layer = 1; Layer < QOfLayers; ++Layer)
        this->SynapsesLayers.emplace_back(layers[Layer],
                                          layers[Layer - 1],
                                          LearnRate,
                                          fAxon
                                         );
}

void Neural_Network::LearnFrom(const DatasList& Data, const DatasList& ExpectedResults) {
     if (ExpectedResults.size() < this->SynapsesLayers.back().LayerResults.size()) ABORT::BecauseOf(WRONG::QUANTITYofRESULTSEXPECTED);

     this->feedWith(Data);

     SynapsesLayers.back().SetExpectedResults(ExpectedResults);


     for (uint16_t Layer = SynapsesLayers.size() - 1; Layer != numeric_limits<uint16_t>::max(); --Layer) {}
//         SynapsesLayers[Layer].BackPropag();
}

DatasList Neural_Network::feedWith(const DatasList& Data) {
          if (Data.size() < this->SynapsesLayers[0].LayerResults.size()) ABORT::BecauseOf(WRONG::QUANTITYofINFORMATION);

          SynapsesLayers[0].feedFrom(Data);
          for (uint16_t Layer = 1; Layer < SynapsesLayers.size(); ++Layer)
              SynapsesLayers[Layer].feedFrom(SynapsesLayers[Layer - 1].LayerResults);

          return SynapsesLayers.back().LayerResults;
}
