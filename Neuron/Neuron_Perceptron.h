/**
    File    : Neuron_Perceptron.h
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190506.1

    Neuron Specialization to Perceptron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef NEURON_PERCEPTRON_H
#define NEURON_PERCEPTRON_H

#include "Neuron.h"

struct Neuron_Perceptron : public Neuron {
       Neuron_Perceptron(const QDedritesType qofDedrites, const double LearnRate, const AxonActFunction& fAxon);

    void LearnFrom(const DatasList& Data, const AxonResult Target);

    private:
        double Error;
};

#endif // NEURON_PERCEPTRON_H
