/**
    File    : Neuron.h
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190319.2

    Neuron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef NEURON_H
#define NEURON_H

#include <functional>
#include <random>
#include <chrono>

using namespace std;

using QDedritesType     = uint8_t;
using DatumType         = double;
using WeightType        = double;
using AxonResult        = double;
using DatasList         = vector<DatumType>;
using WeightsList       = vector<WeightType>;
using AxonActFunction   = function<AxonResult(AxonResult)>;

constexpr double BIAS = 1.0;

struct Neuron {
       Neuron(const QDedritesType qofDedrites, const double LearnRate, const AxonActFunction& fAxonF);

    void LearnFrom(const DatasList& Data, AxonResult Target);
    AxonResult FeedDedritesWith(const DatasList& Data);

    private:
        const AxonActFunction& Axon;

        const QDedritesType QOfDedrites;
        const double LearningRate;

        double Error;

        const DatasList* DedritesD;
        WeightsList DedritesW;

        AxonResult Nucleus() const;
};

#endif // NEURON_H
