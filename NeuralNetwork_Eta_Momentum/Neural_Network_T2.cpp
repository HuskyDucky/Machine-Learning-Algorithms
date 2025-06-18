/**
    File    : Neural_Network_T2.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190923.4

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
#include "Neural_Network_T2.h"
#include <iostream>

NeuralNetT2::NeuralNetT2(const Topology& topology) {

    assert(topology.size() >= 3);
    //Check if all values are bigger than 0;

    uint16_t PosOutputLayer = topology.size() - 1;

    for (uint16_t LayerNum = 0; LayerNum < PosOutputLayer; ++LayerNum) {
        auto AddBiasNeuron = [&]() -> uint16_t { return (LayerNum + 1 == PosOutputLayer)? 0 : 1; }; //Output Layer hasn't the Bias Neuron
        this->Layers.emplace_back();

        const uint16_t NOfNeurons2_ThisLayer = topology[LayerNum] + QOfBIASNeurons;

        for (uint16_t N_Idx = 0; N_Idx < NOfNeurons2_ThisLayer; ++N_Idx)
            Layers.back().emplace_back(N_Idx, topology[LayerNum + 1] + AddBiasNeuron());                   //Save the quantity of Neurons of next layer
    }

    //Output layer
    this->Layers.emplace_back();
    for (uint16_t N_Idx = 0; N_Idx < topology[PosOutputLayer]; ++N_Idx)
        Layers.back().emplace_back(N_Idx, 0);
}

void NeuralNetT2::feedForward(const vector<double>& inputVals) {

     assert(inputVals.size() == this->Layers[0].size() - QOfBIASNeurons);

     //Latch - feed the Input layer with the new values
     for (uint16_t N_Idx = 0; N_Idx < inputVals.size(); ++N_Idx)
         Layers[0][N_Idx].setOutputVal(inputVals[N_Idx]);

     //Propagating forward
     for (uint16_t layerNum = 1; layerNum < Layers.size(); ++layerNum) {
         const uint16_t LayerSize = Layers[layerNum].size() - ((layerNum < Layers.size() - 1)? 1 : 0);      //Output layer has no bias neuron

         for (auto feedNeuron = 0; feedNeuron < LayerSize; ++feedNeuron)
             Layers[layerNum][feedNeuron].feedForwardWithPrevLayer(Layers[layerNum - 1]);                   //Feed the neuron with the previous layer
     }
}

void NeuralNetT2::backProp(const vector<double>& targetVals) {
     //Here is where the NeuralNet learn

     //Calculate overall NeuralNet error (RMS of output neuron errors) - Root Mean Square Error
     Layer& outputLayer = Layers.back();
     this->overallError = 0.0;

     for (uint16_t N_Idx = 0; N_Idx < outputLayer.size(); ++N_Idx) {
         double delta = targetVals[N_Idx] - outputLayer[N_Idx].getOutputVal(); //Error to every result
         this->overallError += delta * delta;
     }
     this->overallError /= outputLayer.size();                                //Average overallError
     this->overallError = sqrt(overallError);                                 //RMS Result

     //Implement a recent measurement:
     this->RecentAverageError = (this->RecentAverageError * this->RecentAverageSmoothFactor + this->overallError)
                              / (this->RecentAverageSmoothFactor + 1.0);

     //Calculate OUTPUT LAYER gradients
     for (uint16_t N_Idx = 0; N_Idx < outputLayer.size(); ++N_Idx)
         outputLayer[N_Idx].CalcOutputGradients(targetVals[N_Idx]);

     //Calculate HIDDEN LAYER gradients - (That include all layers except the input and output layers)
     for (uint16_t LayerNum = Layers.size() - 2; LayerNum > 0; --LayerNum) {
          //Hidden Layer = Layers[LayerNum];
          //Next Layer   = Layers[LayerNum + 1];
          for (uint16_t N_Idx = 0; N_Idx < Layers[LayerNum].size(); ++N_Idx)
              Layers[LayerNum][N_Idx].CalcHiddenGradients(Layers[LayerNum + 1]);
     }

     //For all layers from outputs to first hidden layer - update connections weights
     for (uint16_t LayerNum = Layers.size() - 1; LayerNum > 0; --LayerNum)
         //Curr Layer = Layers[LayerNum];
         //Prev Layer = Layers[LayerNum - 1];
         for (uint16_t N_Idx = 0; N_Idx < Layers[LayerNum].size() - 1; ++N_Idx)
             Layers[LayerNum][N_Idx].updateInputWeights(Layers[LayerNum - 1]);

}

void NeuralNetT2::setResultsInto(vector<double>& resultsVals) const {
     resultsVals.clear();

     for (uint16_t N_Idx = 0; N_Idx < Layers.back().size(); ++N_Idx)
         resultsVals.push_back(Layers.back()[N_Idx].getOutputVal());
}
