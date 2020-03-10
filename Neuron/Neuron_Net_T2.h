/**
    File    : Neuron_Net_T2.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190924.2

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

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
#ifndef Neuron_T2_H
#define Neuron_T2_H

#include <cmath>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

struct NeuronT2;
using Layer = vector<NeuronT2>;

constexpr uint8_t QOfBIASNeurons = 1;

struct NeuronT2 {
       NeuronT2(const uint16_t Idx, const uint16_t NOfOutputs);
      ~NeuronT2() = default;

    void setOutputVal(double newOutput);
    double getOutputVal() const;

    void feedForwardWithPrevLayer(const Layer& prevLayer);

    void CalcOutputGradients(double tagetVal);
    void CalcHiddenGradients(const Layer& NextLayer);

    void updateInputWeights(Layer& PrevLayer);

    private:
        struct Nucleus {
               static double eta;   //overall net learning rate [0.0..1.0]
               static double alpha; // momentum, multiplier of last deltaWeight [0.0..n]
               static double BIAS;

               static mt19937 Base2InitializeWeights;

               static double ActivateOutput(double x) { return tanh(x); }                  //range [-1.0...1.0] - Pass this functions as Lambdas
               static double ActivateDerivativeOutput(double x) { return 1.0 - x * x; }    //when then NeuronT2 class is constructed
        };

        struct Sinapses {
               Sinapses(double NeuronT2Num, uint16_t NOfNeuronT2s);
            double Weight;
            double DeltaWeight; //Change weight in momentum calculation
        };

        uint16_t Index;
        double Output;
        double Gradient;
        vector<Sinapses> Sinapses_OutputWeights;

        //double SumDerivOfWeights(const Layer& NextLayer) const;
};

#endif // NeuronT2_T2_H
