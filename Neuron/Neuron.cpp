/**
    File    : Neuron.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190319.2

    Neuron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Neuron.h"
#include "Neuron_Abort.h"

Neuron::Neuron(const QDedritesType qofDedrites, const double LearnRate, const AxonActFunction& fAxon) :
               Axon(fAxon),
               QOfDedrites(qofDedrites),
               LearningRate(LearnRate),
               Error(0.0) {

    if (this->QOfDedrites == 0) ABORT::BecauseOf(WRONG::QUANTITYofDEDRITES);

    mt19937 RandBase(chrono::steady_clock::now().time_since_epoch().count());
    uniform_real_distribution<WeightType> RandWeight(-1.0, 1.0);

    for (QDedritesType weight = 0; weight <= this->QOfDedrites; ++weight)   //BIAS Weight = DedritesW[QOfDedrites]
        this->DedritesW.emplace_back(RandWeight(RandBase));
}

AxonResult Neuron::FeedDedritesWith(const DatasList& Data) {
           if (Data.size() != this->QOfDedrites) ABORT::BecauseOf(WRONG::QUANTITYofDATA);

           this->DedritesD = &Data;

           return  Axon(Nucleus());
}

AxonResult Neuron::Nucleus() const {
           AxonResult DWSum = BIAS * this->DedritesW[this->QOfDedrites];

           for (QDedritesType SDW = 0; SDW < this->QOfDedrites; ++SDW)
               DWSum += (*this->DedritesD)[SDW] * this->DedritesW[SDW];

           return DWSum;
}

void Neuron::LearnFrom(const DatasList& Data, AxonResult Target) {
     this->Error = Target - this->FeedDedritesWith(Data);

     this->DedritesW[this->QOfDedrites] += this->Error * this->LearningRate * BIAS;

     if (this->Error)
        for (QDedritesType newW = 0; newW < this->QOfDedrites; ++newW)
            this->DedritesW[newW] += this->Error * this->LearningRate * (*this->DedritesD)[newW];
}
