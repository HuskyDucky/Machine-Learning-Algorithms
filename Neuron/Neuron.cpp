/**
    File    : Neuron.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190506.1

    Neuron Base

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Neuron.h"

Neuron::Neuron(const QDedritesType qofDedrites, const double LearnRate, const AxonActFunction& fAxon) :
               Axon(fAxon),
               QOfDedrites(qofDedrites),
               LearningRate(LearnRate),
               DedritesD(QOfDedrites, 0.0),
               Result(0.0) {

    if (this->QOfDedrites < 2) ABORT::BecauseOf(WRONG::QUANTITYofDEDRITES);

    mt19937 RandBase(chrono::steady_clock::now().time_since_epoch().count());
    uniform_real_distribution<WeightType> RandWeight(0.0, 1.0);

    for (QDedritesType weight = 0; weight <= this->QOfDedrites; ++weight)   //BIAS Weight = DedritesW[QOfDedrites]
        this->DedritesW.emplace_back(RandWeight(RandBase));
}

AxonResult Neuron::FeedDedritesWith(const DatasList& Data) {
           if (Data.size() != this->QOfDedrites) ABORT::BecauseOf(WRONG::QUANTITYofDATA);

           this->DedritesD = Data;

           this->Result = Axon(Nucleus());
           return  this->Result;
}

AxonResult Neuron::Nucleus() const {
           AxonResult DWSum = BIAS * this->DedritesW[this->QOfDedrites];

           for (QDedritesType SDW = 0; SDW < this->QOfDedrites; ++SDW)
               DWSum += this->DedritesD[SDW] * this->DedritesW[SDW];

           return DWSum;
}

