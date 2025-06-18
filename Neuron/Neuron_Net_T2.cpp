/**
    File    : Neuron_Netw_T2.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190924.3

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

NeuronT2::Sinapses::Sinapses(double NeuronNum, uint16_t NOfNeurons) :
        Weight(uniform_real_distribution<double>( NeuronNum     /NOfNeurons,    //Define which part of interval [0...1] this sinapse will get
                                                 (NeuronNum + 1)/NOfNeurons)    //based on total of neurons are conected to. (NOfSinapses = NOfNeuronsConnected)
                                                 (NeuronT2::Nucleus::Base2InitializeWeights)) {}

NeuronT2::NeuronT2(const uint16_t Idx, const uint16_t NOfOutputs) :
        Index(Idx),
        Output(NeuronT2::Nucleus::BIAS),
        Gradient(0.0) {

        for (uint16_t IIt = 0; IIt < NOfOutputs; ++IIt)
            Sinapses_OutputWeights.emplace_back(IIt, NOfOutputs);
}

void NeuronT2::feedForwardWithPrevLayer(const Layer& prevLayer) {
     double Sum = 0.0;

     for (auto& prevL : prevLayer)
         Sum += prevL.getOutputVal() *
                prevL.Sinapses_OutputWeights[this->Index].Weight;

     this->Output = NeuronT2::Nucleus::ActivateOutput(Sum);
}

//Helps to reduce the overall Error
void NeuronT2::CalcOutputGradients(double targetVal) {
     double delta = targetVal - this->Output;
     this->Gradient = delta * NeuronT2::Nucleus::ActivateDerivativeOutput(this->Output);
}

void NeuronT2::CalcHiddenGradients(const Layer& NextLayer) {
     this->Gradient = 0.0; //Sum Derivative Of Weights - SDofW is a contributions of the errors at the nodes we feed

     for (uint16_t N_Idx = 0; N_Idx < NextLayer.size(); ++N_Idx)
         this->Gradient += this->Sinapses_OutputWeights[N_Idx].Weight * NextLayer[N_Idx].Gradient;

     this->Gradient *= NeuronT2::Nucleus::ActivateDerivativeOutput(this->Output);
}

void NeuronT2::updateInputWeights(Layer& PrevLayer) {
     for (uint16_t N_Idx = 0; N_Idx < PrevLayer.size(); ++N_Idx) {
         double oldDeltaWeight = PrevLayer[N_Idx].Sinapses_OutputWeights[this->Index].DeltaWeight;

         double newDeltaWeight = //Individual input, magnified by the Gradient and Train rate
                                 NeuronT2::Nucleus::eta *
                                 PrevLayer[N_Idx].getOutputVal() *
                                 this->Gradient +
                                 //Also add momentum = a fraction of previous delta weight
                                 NeuronT2::Nucleus::alpha *
                                 oldDeltaWeight;

         PrevLayer[N_Idx].Sinapses_OutputWeights[this->Index].DeltaWeight = newDeltaWeight;
         PrevLayer[N_Idx].Sinapses_OutputWeights[this->Index].Weight += newDeltaWeight;

     }
}

void NeuronT2::setOutputVal(double newOutput) {
     this->Output = newOutput; }

double NeuronT2::getOutputVal() const {
       return this->Output; }
