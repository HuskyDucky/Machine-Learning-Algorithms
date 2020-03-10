/**
    File    : Perceptron_run_Functions.h
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190324.1

    Perceptron

    BSD License

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
#ifndef PERCEPTRON_RUN_H
#define PERCEPTRON_RUN_H

#include <array>
#include <vector>
#include <optional>
#include <functional>

#include <iostream>
#include <iomanip>

using namespace std;

#include "Perceptron.h"

struct pointlimit {
       pointlimit(int16_t i, int16_t e) : Ini(i), End(e) {}
       int16_t Ini;
       int16_t End;
};

using TargetFunction = function<double(vector<double>)>;

struct PointsGenerator {
       PointsGenerator(const vector<DatasList>& CPoints,
                       const vector<pointlimit>& xylim);

    //This version works just with 2 coordinates
    XYR2LearnWith GenerateAndPrintTrainingPoints(const uint16_t QOfTrainingPoints, const TargetFunction& TargetF, const AxonActFunction& ActFunction);
    XY CopyFirstPoints(const uint16_t TotPoints) const;
    vector<DatasList>::size_type QOfCriticalPoints() const;

    private:
        const vector<DatasList> CriticalPoints;
        const vector<pointlimit> xylimits;
        XY xy;

        void GenerateRandomPoints(const uint16_t QOfElements);
};

void PrintResults(const bool PrintLine,
                  uint16_t Pos,
                  const XY& xy,
                  AxonResult Guess,
                  const XYR2LearnWith& Target);
void ShowPoint(const bool PrintLine,
               int16_t dedriteX,
               int16_t dedriteY,
               AxonResult Position,
               optional<AxonResult> Result = nullopt);

#endif // PERCEPTRON_RUN_H
