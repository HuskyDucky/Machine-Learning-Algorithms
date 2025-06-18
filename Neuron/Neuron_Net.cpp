/**
    File    : Neuron_Net.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190506.2

    Neuron Specialization to network

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
#include "Neuron_Net.h"

Neuron_Net::Neuron_Net(const QDedritesType qofDedrites,
                       const double LearnRate,
                       const AxonActFunction& fAxon) : Neuron (qofDedrites, LearnRate, fAxon),
                                                       AdjIdx(1.0),
                                                       Adjustment(QOfDedrites, 0.0) {}

AxonResults Neuron_Net::LearnFrom(const AxonResult Target) {
            this->AdjIdx = 1.0 - (Target - this->Result) / Target;

            this->DedritesW[this->QOfDedrites] *= this->AdjIdx;                                          //BIAS weight adjustment

            for (QDedritesType dedrite = 0; dedrite < this->QOfDedrites; ++dedrite) {
                this->DedritesW[dedrite] *= this->AdjIdx;

                this->Adjustment[dedrite] = this->DedritesD[dedrite] +
                                            this->DedritesD[dedrite] *
                                            this->AdjIdx;   //New targets to every dedrite
             }

           return this->Adjustment;
}

