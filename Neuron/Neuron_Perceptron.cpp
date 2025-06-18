/**
    File    : Neuron_Perceptron.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190506.1

    Neuron Specialization to Perceptron

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
#include "Neuron_Perceptron.h"

Neuron_Perceptron::Neuron_Perceptron(const QDedritesType qofDedrites,
                                     const double LearnRate,
                                     const AxonActFunction& fAxon) : Neuron (qofDedrites, LearnRate, fAxon),
                                                                     Error(0.0) {}

void Neuron_Perceptron::LearnFrom(const DatasList& Data, const AxonResult Target) {
     this->Error = Target - this->FeedDedritesWith(Data);

     this->DedritesW[this->QOfDedrites] += this->Error * this->LearningRate * BIAS;

     if (this->Error)
        for (QDedritesType newW = 0; newW < this->QOfDedrites; ++newW)
            this->DedritesW[newW] += this->Error * this->LearningRate * this->DedritesD[newW];
}
