/**
    File    : Neural_Network_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.25            Version: 20190325.1

    Neural_Network

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include <iostream>
#include <iomanip>

#include "Neural_Network.h"

AxonResult ActivationFunction(AxonResult x) { return x / 1.0 + abs(x); }    //Sigmoid

void Run_Neural_Network() {

     Neural_Network NNet({2,4,2}, 0.01, ActivationFunction);

     NNet.LearnFrom({0, 0}, {1});

     auto Results = NNet.feedWith({0, 0});

     for (auto IIt : Results)
         cout << "\nResult: " << setprecision(15) << IIt;

}
