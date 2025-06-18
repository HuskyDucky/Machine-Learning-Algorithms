/**
    File    : Neural_Network_T2_Run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190928.1

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
#include <vector>
#include <cassert>

#include <iostream>

#include "Neural_Network_T2.h"
#include "Neural_Network_T2_TrainingData.h"

using namespace std;

void showVectorVals(const string label, vector<double>& Vec) {

     cout << label << " ";

     for (uint16_t IIt = 0; IIt < Vec.size(); ++IIt)
         cout << Vec[IIt] << " ";

     cout << endl;
}

int Run_Neural_Network_T2() {

    TrainingData trainData("Back_Propagation/Neural_Network_T2_TrainingData.txt");

    if (trainData.isNOT_DataTrainingFileOpen()) return 1;

    vector<uint16_t> topology;
    trainData.setTopologyInto(topology);

    NeuralNetT2 NeNe(topology);

    vector<double> inputVals, targetVals, resultVals;
    uint16_t trainingPass = 0;

    while (!trainData.isEof()) {
          ++trainingPass;

          cout << "\nPass " << trainingPass;

          //Get new input data and feed it forward:
          if (trainData.setNextInputsInto(inputVals) != topology[0])
             break;

          NeNe.feedForward(inputVals);

          //Collect the net's actual results:
          NeNe.setResultsInto(resultVals);

          //Train the net what the outputs should have been
          trainData.setTargetOutputsInto(targetVals);

          showVectorVals(":\nInputs:", inputVals);
          showVectorVals("Result Target:", targetVals);
          showVectorVals("Result Output:", resultVals);

          assert(targetVals.size() == topology.back());

          NeNe.backProp(targetVals);

          //Report how well the training is working, averaged over results
          cout << "Net recent average error: "
               << NeNe.getRecentAverageError() << endl;

    }

    cout << "\nDone.";

    return 0;
}
