/**
    File    : Neural_Network_T2_TrainingData.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190928.1

    XOR results. Based on Dave Muller example.

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright (c) 2019     All rights reserved.

    Software distributed under the License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef TRAINING_H
#define TRAINING_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

//Silly class to read and training data from a file
struct TrainingData {
       TrainingData(const string& filename);

    bool openDataTrainingFile(const string filename);

    bool isNOT_DataTrainingFileOpen() const;

    bool isEof() const { return TrainingDataFile.eof(); }
    void setTopologyInto(vector<uint16_t>& topology);

    //returns the number of input values read from the file:
    uint16_t setNextInputsInto(vector<double>& inputVals);
    uint16_t setTargetOutputsInto(vector<double>& targetOutputVals);

    private:
        bool isGood2Go;
        ifstream TrainingDataFile;
};

#endif // TRAINING_H
