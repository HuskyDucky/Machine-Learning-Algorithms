/**
    File    : Perceptron_run_Functions.h
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190322.1

    Perceptron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef PERCEPTRON_RUN_H
#define PERCEPTRON_RUN_H

#include <vector>
#include <optional>
#include <functional>

#include <iostream>
#include <iomanip>

using namespace std;

#include "Perceptron.h"

using TargetFunction = function<double(vector<double>)>;

XY GenerateRandomPoints(const uint16_t QOfElements);
XY CopyThe15FirstPointsFrom(const XYR2LearnWith& xyr);
void PrintResults(uint16_t Pos, const XY& xy, AxonResult Guess, const XYR2LearnWith& Target);
void ShowPoint(int16_t dedriteX, int16_t dedriteY, AxonResult Position, optional<AxonResult> Result = nullopt);
XYR2LearnWith GenerateAndPrintTrainingPoints(const uint16_t QOfTrainingPoints, const TargetFunction& TargetF, const AxonActFunction& ActFunction);

#endif // PERCEPTRON_RUN_H
