/**
    File    : Neural_Network.h
    Author  : Menashe Rosemberg
    Created : 2019.03.25            Version: 20190325.2

    Neural_Network

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "Neural_Network_Synapses.h"

struct Neural_Network {
       Neural_Network(const vector<uint16_t> layers, const double LearnRate, const AxonActFunction& fAxon);

       DatasList feedWith(const DatasList& Data);
       void LearnFrom(const DatasList& Data, const DatasList& Expected);

    private:
        vector<Synapses> SynapsesLayers;
};


#endif // NEURAL_NETWORK_H
