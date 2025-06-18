/**
    File    : Neuron_Net_T2_Nucleus.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190304.5

    Basic Neural Back-propagation based on Dave Muller example

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
#include "Neuron_Net_T2.h"

double NeuronT2::Nucleus::eta     = 0.1;  //overall net learning rate [0.0..1.0]                  -> 0.0 = Slow learner, 0.2 = Medium learner, 1.0 = reckless learner
double NeuronT2::Nucleus::alpha   = 0.33; //momentum, multiplier of last deltaWeight [0.0..n]     -> 0.0 = no momentum, 0.5 = moderate momentum
double NeuronT2::Nucleus::BIAS    = 1.0;

mt19937 NeuronT2::Nucleus::Base2InitializeWeights(chrono::steady_clock::now().time_since_epoch().count());
