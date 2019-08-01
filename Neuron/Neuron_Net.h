/**
    File    : Neuron_Net.h
    Author  : Menashe Rosemberg
    Created : 2019.03.19            Version: 20190507.1

    Neuron Specialization to Network

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef NEURON_NET_H
#define NEURON_NET_H

#include "Neuron.h"

using AxonResults = vector<AxonResult>;

struct Neuron_Net : public Neuron {
       Neuron_Net(const QDedritesType qofDedrites, const double LearnRate, const AxonActFunction& fAxon);

    AxonResults LearnFrom(const AxonResult Target);

    private:
        AxonResult AdjIdx;
        AxonResults Adjustment;
};


#endif // NEURON_NET_H
