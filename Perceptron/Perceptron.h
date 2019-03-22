/**
    File    : Perceptron_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190321.1

    Perceptron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "../Neuron/Neuron.h"

using XYR2LearnWith   = vector<pair<DatasList, AxonResult>>;
using XY              = vector<DatasList>;

struct Perceptron : Neuron {
       Perceptron(const QDedritesType qofDedrites, const double LearnRate, const AxonActFunction& fAxonF);

    void Training(const XYR2LearnWith& xyr);
    AxonResult run(const DatasList& xy);
};

#endif // PERCEPTRON_H
