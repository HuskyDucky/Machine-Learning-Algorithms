/**
    File    : Perceptron_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190324.2

    Perceptron

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
#include "Perceptron.h"
#include "Perceptron_run_Functions.h"

void Run_Perceptron() {
     auto TargetLinearFunction  = [](const vector<double>& xy) -> double { return 2.0 * xy[0] + 3.0 - xy[1]; };
     const uint16_t Coordenates = 2;
     const double LearningRate  = 0.01;
     auto ActivationFunction    = [](AxonResult AxR) -> AxonResult { return AxR > 0.0 ?  1.0 : -1.0; };

     PointsGenerator Points({{-10.0,-17.0},     //edge over f(x)
                             { 10.0, 23.0},     //edge over f(x)
                             {  0.0,  3.0},     //over f(x)
                             {  6.0, 15.0},     //over f(x)
                             { -9.0,-15.0}      //over f(x)
                            },
                            {{-10, 10},         //Graph limit to x
                             {-17, 23}          //Graph limit to y
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
