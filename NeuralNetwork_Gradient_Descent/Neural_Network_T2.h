/**
    File    : Neural_Network_T2.h
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190302.5

    Basic Neural Back-propagation based on Dave Muller example

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright (c) 2019     All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
