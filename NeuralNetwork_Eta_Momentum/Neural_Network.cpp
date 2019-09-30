/**
    File    : Neural_Network.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.25            Version: 20190327.1

    Neural_Network

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Neural_Network.h"

Neural_Network::Neural_Network(const vector<uint16_t> layers,
                               const double LearnRate,
                               const AxonActFunction& fAxon) {
    const auto QOfLayers = layers.size();

    if (QOfLayers < 3) ABORT::BecauseOf(WRONG::QUANTITYofLAYERS);

    this->SynapsesLayers.reserve(QOfLayers);

    this->SynapsesLayers.emplace_back(layers[0]);           //It doesn't have real neurons and just transfer the data to next layer
    for (uint8_t Layer = 1; Layer < QOfLayers; ++Layer)
        this->SynapsesLayers.emplace_back(layers[Layer],
                                          layers[Layer - 1],
                                          LearnRate,
                                          fAxon
                                         );
}

DatasList Neural_Network::feedWith(const DatasList& Data) {
          if (Data.size() < this->SynapsesLayers[0].LayerResults.size()) ABORT::BecauseOf(WRONG::QUANTITYofINFORMATION);

          SynapsesLayers[0].feedFrom(Data);
          for (uint16_t Layer = 1; Layer < SynapsesLayers.size(); ++Layer)
              SynapsesLayers[Layer].feedFrom(SynapsesLayers[Layer - 1].LayerResults);

          return SynapsesLayers.back().LayerResults;
}

void Neural_Network::LearnFrom(const DatasList& Data, const DatasList& ExpectedResults) {
     if (ExpectedResults.size() < this->SynapsesLayers.back().LayerResults.size()) ABORT::BecauseOf(WRONG::QUANTITYofRESULTSEXPECTED);

     this->feedWith(Data);

     SynapsesLayers.back().SetExpectedResults(ExpectedResults);


     for (uint16_t Layer = SynapsesLayers.size() - 1; Layer != numeric_limits<uint16_t>::max(); --Layer) {}
//         SynapsesLayers[Layer].BackPropag();
}
