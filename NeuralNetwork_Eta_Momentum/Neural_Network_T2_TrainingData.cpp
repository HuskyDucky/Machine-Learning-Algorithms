/**
    File    : Neural_Network_T2_TrainingData.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.03            Version: 20190928.1

    XOR results. Based on Dave Muller example.

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright (c) 2019     All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Neural_Network_T2_TrainingData.h"

TrainingData::TrainingData(const string& filename) {
    this->isGood2Go = this->openDataTrainingFile(filename);
}

bool TrainingData::openDataTrainingFile(const string filename) {
     TrainingDataFile.open(filename.c_str());

     if (!TrainingDataFile.is_open()) {
        cout << "\nI couldn't open the file " << filename << '.'
             << "\nCreate this file with the follow content:"
             << "\ntopology: <Layer in> <Layer Hidden> <Layer out>"
             << "\nin: <Val in 1> <Val in 2> ... -> <Val in X> must be the same as <Layer in>"
             << "\nout: <Val out 1> ...          -> <Val out X> must be the same as <Layer out>"
             << "\n-> add several lines 'in:|out:' to create a good quantity of data training."
             << "\n\nFor example:\n"
             << "\ntopology: 2 4 1"
             << "\nin: 1.0 0.0"
             << "\nout: 1.0"
             << "\nin: 1.0 1.0"
             << "\nout: 0.0"
             << "\n..." << endl;
        return false;
    }

    return true;
}

bool TrainingData::isNOT_DataTrainingFileOpen() const { return !this->isGood2Go; }

void TrainingData::setTopologyInto(vector<uint16_t>& topology) {
     if (this->isGood2Go) {

         string line;
         string label;

         getline(TrainingDataFile, line);
         stringstream ss(line);
         ss >> label;
         if (this->isEof() || label.compare("topology:") != 0)
            abort();

         while (!ss.eof()) {
               uint16_t n;
               ss >> n;
               topology.push_back(n);
         }
     }
}

uint16_t TrainingData::setNextInputsInto(vector<double>& inputVals) {
         if (this->isGood2Go) {
            inputVals.clear();

            string line;
            getline(TrainingDataFile, line);
            stringstream ss(line);

            string label;
            ss >> label;

            if (label.compare("in:") == 0) {
               double oneValue;
               while (ss >> oneValue)
                     inputVals.push_back(oneValue);
            }
         }

         return inputVals.size();
}

uint16_t TrainingData::setTargetOutputsInto(vector<double>& targetOutputVals) {
         if (this->isGood2Go) {

             targetOutputVals.clear();

             string line;
             getline(TrainingDataFile, line);
             stringstream ss(line);

             string label;
             ss >> label;

             if (label.compare("out:") == 0) {
                double oneValue;
                while (ss >> oneValue)
                      targetOutputVals.push_back(oneValue);
             }
         }

         return targetOutputVals.size();
}
