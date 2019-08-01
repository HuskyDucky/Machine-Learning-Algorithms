/**
    File    : Neuron_Net.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190506.2

    Neuron Specialization to network

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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

