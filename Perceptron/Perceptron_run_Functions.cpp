/**
    File    : Perceptron_run_Functions.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190324.3

    Perceptron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Perceptron_run_Functions.h"

PointsGenerator::PointsGenerator(const vector<DatasList>& CPoints, const vector<pointlimit>& xylim) :
                                CriticalPoints(CPoints),
                                xylimits(xylim) {}

vector<DatasList>::size_type PointsGenerator::QOfCriticalPoints() const {
    return this->CriticalPoints.size(); }

    //This version works just with 2 coordinates
XYR2LearnWith PointsGenerator::GenerateAndPrintTrainingPoints(const uint16_t QOfTrainingPoints,
                                                              const TargetFunction& TargetF,
                                                              const AxonActFunction& ActFunction) {

              this->GenerateRandomPoints((QOfTrainingPoints - this->CriticalPoints.size() < 75) ?
                                                                                            75 :
                                                                                            (QOfTrainingPoints - this->CriticalPoints.size()));
              for (auto crp : this->CriticalPoints)
                  this->xy.insert(xy.begin(), crp);

              XYR2LearnWith xyr;
              for (auto x_y : xy)
                  xyr.emplace_back(x_y, ActFunction(TargetF(x_y)));

              return xyr;
}

XY PointsGenerator::CopyFirstPoints(uint16_t TotPoints) const {
   return XY(this->xy.begin(), this->xy.begin() + (TotPoints < this->xy.size()? TotPoints : this->xy.size())); }


void PointsGenerator::GenerateRandomPoints(const uint16_t QOfElements) {
   cout << "\nGenerating Random Point: ";

   this->xy.clear();
   this->xy.resize(QOfElements);

   mt19937 RandPosBase(chrono::steady_clock::now().time_since_epoch().count());
   uniform_int_distribution<int16_t> RandPos_X(this->xylimits[0].Ini, this->xylimits[0].End);                      //Graph limit
   uniform_int_distribution<int16_t> RandPos_Y(this->xylimits[1].Ini, this->xylimits[1].End);                      //Graph limit

   for (uint16_t IIt = 0; IIt < QOfElements; ++IIt) {
        this->xy[IIt].emplace_back(RandPos_X(RandPosBase));
        this->xy[IIt].emplace_back(RandPos_Y(RandPosBase));
   }

   cout << " done.";
}

void PrintResults(const bool PrintLine, uint16_t Pos, const XY& xy, AxonResult Guess, const XYR2LearnWith& Target) {
     ShowPoint(PrintLine,
               xy[Pos][0],          //X
               xy[Pos][1],          //Y
               Guess,               //Guess
               Target[Pos].second);
}

void ShowPoint(const bool PrintLine, int16_t dedriteX, int16_t dedriteY, AxonResult Position, optional<AxonResult> Result) {

     if (PrintLine)
        cout << '\n' << string(30, '-') << " End of critical points";

     cout << "\nX: " << setw(3) << dedriteX
          <<  " Y: " << setw(3) << dedriteY
          <<  " => " << (Position > 0.0 ? "over ":"below");

     if (Result != nullopt)
        cout << (Position == Result.value()? " Passed" : "\tFailed");
}

