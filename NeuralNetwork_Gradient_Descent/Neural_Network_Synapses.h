/**
    File    : Neural_Network_Synapses.h
    Author  : Menashe Rosemberg
    Created : 2019.03.25            Version: 20190328.2

    Neural Network

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
