/**
    File    : Neuron_Net_T2.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190924.2

    Basic Neural Back-propagation based on Dave Muller example

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright (c) 2019     All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
