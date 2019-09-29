/**
    File    : Neuron_Netw_T2.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190924.3

    Basic Neural Back-propagation based on Dave Muller example

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright (c) 2019     All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
