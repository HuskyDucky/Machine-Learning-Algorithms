/**
    File    : Perceptron_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190321.2

    Perceptron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Perceptron.h"

Perceptron::Perceptron(const QDedritesType qofDedrites,
                       const double LearnRate,
                       const AxonActFunction& fAxonF) : Neuron(qofDedrites, LearnRate, fAxonF) {}

void Perceptron::Training(const XYR2LearnWith& xyr) {
     for (uint16_t Teach = 0; Teach < xyr.size(); ++Teach)
          this->LearnFrom(xyr[Teach].first, xyr[Teach].second); }

AxonResult Perceptron::run(const DatasList& xy) {
           return this->FeedDedritesWith(xy); }
