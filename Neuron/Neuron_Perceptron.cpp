/**
    File    : Neuron_Perceptron.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190506.1

    Neuron Specialization to Perceptron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
