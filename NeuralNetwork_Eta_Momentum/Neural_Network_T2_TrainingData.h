/**
    File    : Neural_Network_T2_TrainingData.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190928.1

    XOR results. Based on Dave Muller example.

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

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
