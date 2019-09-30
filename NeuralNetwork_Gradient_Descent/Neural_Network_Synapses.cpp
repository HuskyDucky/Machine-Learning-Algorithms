/**
    File    : Neural_Network_Synapses.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.25            Version: 20190327.1

    Neural_Network

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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

AdjustmentType Synapses::BackPropag(const AxonResultsType& ExpectedResults) {
//     for (QNeuronsType NNeu = 0; NNeu < this->QOfNeurons; ++NNeu)
//         this->Adjustment[NNeu] = this->Neurons[NNeu].LearnFrom(Expected[NNeu]);

    return this->Adjustments;
}

#endif // SYNAPSES_H
