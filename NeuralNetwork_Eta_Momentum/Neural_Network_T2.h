/**
    File    : Neural_Network_T2.h
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190302.5

    Basic Neural Back-propagation based on Dave Muller example

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
#ifndef NEURAL_NETWORK_T2_H
#define NEURAL_NETWORK_T2_H

#include <cmath>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

using namespace std;

#include "../Neuron/Neuron_Net_T2.h"

using Topology = vector<uint16_t>;

struct NeuralNetT2 {
       NeuralNetT2(const Topology& topology);
      ~NeuralNetT2() = default;

    void feedForward(const vector<double>& inputVals);
    void backProp(const vector<double>& targetVals);
    void setResultsInto(vector<double>& resultsVals) const;
    double getRecentAverageError() const { return this->RecentAverageError; }

    private:
        double overallError;
        double RecentAverageError;
        double RecentAverageSmoothFactor;

        vector<Layer> Layers;
};

#endif // NEURAL_NETWORK_T2_H
