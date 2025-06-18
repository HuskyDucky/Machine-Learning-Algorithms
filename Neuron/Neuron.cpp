/**
    File    : Neuron.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190506.1

    Neuron Base

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

