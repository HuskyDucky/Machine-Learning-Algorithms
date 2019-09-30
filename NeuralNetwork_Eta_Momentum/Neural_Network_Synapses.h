/**
    File    : Neural_Network_Synapses.h
    Author  : Menashe Rosemberg
    Created : 2019.03.25            Version: 20190328.2

    Neural Network

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef NEURAL_NETWORK_SYNAPSES_H
#define NEURAL_NETWORK_SYNAPSES_H

//PASSAR PARA OS NEURONIOS O RANGE PARA GERACAO DE PESOS ALEATORIOS SEGUNDO A PELA POSICAO DO NEURONIO

#include <vector>
//#include <thread>

#include "../Neuron/Neuron_Net.h"
//#include "../_lib_/Abort.h"

using QNeuronsType    = uint8_t;
using QDedritesType   = uint8_t;
using AxonResultsType = vector<AxonResult>;
using AdjustmentType  = vector<AxonResultsType>;

using namespace std;

struct Synapses {
       Synapses(const QDedritesType QOfPseudoNeurons);
       Synapses(const QNeuronsType QOf_Neurons,
                const QDedritesType QOf_Dedrites,
                const double LearnRate,
                const AxonActFunction& fAxon);

    void feedFrom(const AxonResultsType& PreviousLayerResults);
    AdjustmentType SetExpectedResults(const AxonResultsType& ExpectedResults);
    AdjustmentType BackPropag(const AxonResultsType& ExpectedResults);

    AxonResultsType LayerResults;
    AdjustmentType Adjustments;

    private:
        const QNeuronsType QOfNeurons;
        const QDedritesType QOfDedrites;
        vector<Neuron_Net> Neurons;
};

#endif // NEURAL_NETWORK_SYNAPSES_H
