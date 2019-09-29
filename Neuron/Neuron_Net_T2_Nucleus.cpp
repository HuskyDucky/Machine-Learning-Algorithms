/**
    File    : Neuron_Net_T2_Nucleus.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190304.5

    Basic Neural Back-propagation based on Dave Muller example

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright (c) 2019     All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Neuron_Net_T2.h"

double NeuronT2::Nucleus::eta     = 0.1;  //overall net learning rate [0.0..1.0]                  -> 0.0 = Slow learner, 0.2 = Medium learner, 1.0 = reckless learner
double NeuronT2::Nucleus::alpha   = 0.33; //momentum, multiplier of last deltaWeight [0.0..n]     -> 0.0 = no momentum, 0.5 = moderate momentum
double NeuronT2::Nucleus::BIAS    = 1.0;

mt19937 NeuronT2::Nucleus::Base2InitializeWeights(chrono::steady_clock::now().time_since_epoch().count());
