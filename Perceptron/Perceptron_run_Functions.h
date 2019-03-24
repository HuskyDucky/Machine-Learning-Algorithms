/**
    File    : Perceptron_run_Functions.h
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190324.1

    Perceptron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
