/**
    File    : Perceptron_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190324.1

    Perceptron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Perceptron.h"
#include "Perceptron_run_Functions.h"

double TargetLinearFunction(const vector<double>& xy) { return 2.0 * xy[0] + 3.0 - xy[1]; }

const uint16_t Coordenates = 2;
const double LearningRate   = 0.01;
AxonResult ActivationFunction(AxonResult AxR) { return AxR > 0.0 ?  1.0 : -1.0; }

void Run_Perceptron() {

     PointsGenerator Points({{-10.0,-17.0},     //edge over f(x)
                             { 10.0, 23.0},     //edge over f(x)
                             {  0.0,  3.0},     //over f(x)
                             {  6.0, 15.0},     //over f(x)
                             { -9.0,-15.0}      //over f(x)
                            },
                            {{-10, 10},//Graph limit to x
                             {-17, 23}//Graph limit to y
                            });

     XYR2LearnWith xyr = Points.GenerateAndPrintTrainingPoints(200,
                                                               TargetLinearFunction,
                                                               ActivationFunction);
     cout << "Print the Training Points\n";
     for (uint16_t Pos = 0; Pos < xyr.size(); ++Pos)
         ShowPoint(Pos == Points.QOfCriticalPoints(),
                   xyr[Pos].first[0],
                   xyr[Pos].first[1],
                   xyr[Pos].second);

     Perceptron perceptron(Coordenates, LearningRate, ActivationFunction);
                perceptron.Training(xyr);

    cout << "\n\nList of Test Points:\n";
     XY xy = Points.CopyFirstPoints(15);
     for (uint16_t Pos = 0; Pos < xy.size(); ++Pos) {

         AxonResult ResultPos = perceptron.run(xy[Pos]);

         PrintResults(Pos == Points.QOfCriticalPoints(),
                      Pos,
                      xy,
                      ResultPos,
                      xyr);
     }
}
