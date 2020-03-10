/**
    File    : Neural_Network_Synapses.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.25            Version: 20190327.1

    Neural_Network

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

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
#ifndef SYNAPSES_H
#define SYNAPSES_H

#include "Neural_Network_Synapses.h"

Synapses::Synapses(const QDedritesType QOfPseudoNeurons) : LayerResults(QOfPseudoNeurons, 0.0),     //First layer
                                                           QOfNeurons(0),
                                                           QOfDedrites(1) { cout << "Num of Dedrites " << static_cast<int>(QOfDedrites); }

Synapses::Synapses(const QNeuronsType QOf_Neurons, const QDedritesType QOf_Dedrites, const double LearnRate, const AxonActFunction& fAxon) :
                   LayerResults(QOf_Neurons, 0.0),
                   Adjustments(QOf_Neurons, AxonResultsType(QOf_Dedrites, 0.0)),
                   QOfNeurons(QOf_Neurons),
                   QOfDedrites(QOf_Dedrites) {

    this->Neurons.reserve(QOf_Neurons);
    for (QNeuronsType NNeu = 0; NNeu < QOf_Neurons; ++NNeu)
        Neurons.emplace_back(QOf_Dedrites, LearnRate, fAxon);

    cout << "Num of Dedrites " << static_cast<int>(QOfDedrites);
}

void Synapses::feedFrom(const AxonResultsType& PreviousLayerResults) {
     if (this->QOfNeurons)
/*         vector<thread> T;
         T.reserve(QOfNeurons);
         for (QNeuronsType NNeu = 0; NNeu < QOfNeurons; ++NNeu)
             T.emplace_back([&]() { this->LayerResults[NNeu] = this->Neurons[NNeu].FeedDedritesWith(PreviousLayerResults); });
         for (QNeuronsType NNeu = 0; NNeu < QOfNeurons; ++NNeu)
              T[NNeu].join();*/
         for (QNeuronsType NNeu = 0; NNeu < QOfNeurons; ++NNeu)
             this->LayerResults[NNeu] = this->Neurons[NNeu].FeedDedritesWith(PreviousLayerResults);     //USE EXECUTE PARALLELISM FROM c++17 IN THE FUTURE
     else
         this->LayerResults = PreviousLayerResults;                         //this layer is the first one and PreviousLayerResults are the initial data
}

AdjustmentType Synapses::SetExpectedResults(const AxonResultsType& Expected) {
    for (QNeuronsType NNeu = 0; NNeu < this->QOfNeurons; ++NNeu)
        //for (QDedritesType NDe = 0; NDe < this->QOfDedrites; ++NDe)
            this->Adjustments[NNeu] = this->Neurons[NNeu].LearnFrom(Expected[NNeu]);

//     for (QNeuronsType NNeu = 0; NNeu < this->QOfNeurons; ++NNeu)
         //for (QDedritesType NDe = 0; NDe < this->QOfDedrites; ++NDe)
             //this->Error[NNeu][NDe] = Expected[NNeu];
//             this->Adjustment = this->Neurons[NNeu].LearnFrom(Expected[NNeu]);

    return this->Adjustments;
}

//AdjustmentType Synapses::BackPropag(const AxonResultsType& ExpectedResults) {
//     for (QNeuronsType NNeu = 0; NNeu < this->QOfNeurons; ++NNeu)
//         this->Adjustment[NNeu] = this->Neurons[NNeu].LearnFrom(Expected[NNeu]);

//    return this->Adjustments;
//}

#endif // SYNAPSES_H
