/**
    File    : Neural_Network_T2_Run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190928.1

    Basic Neural Back-propagation based on Dave Muller example

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright (c) 2019     All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
