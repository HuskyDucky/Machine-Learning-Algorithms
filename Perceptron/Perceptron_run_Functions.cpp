/**
    File    : Perceptron_run_Functions.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190322.1

    Perceptron

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Perceptron_run_Functions.h"

struct {
    void InsertInto(XY& xy) const {
         for (auto crp : this->Points)
             xy.insert(xy.begin(), crp);
    }

    auto size() const {
         return this->Points.size();
    }

    private:
        vector<DatasList> Points {{-10.0,-17.0},    //edge over f(x)
                                  { 10.0, 23.0},    //edge over f(x)
                                  {  0.0,  3.0},    //over f(x)
                                  {  6.0, 15.0},    //over f(x)
                                  { -9.0,-15.0}     //over f(x)
                                 };
} CriticalPoints;

XY GenerateRandomPoints(const uint16_t QOfElements) {
   cout << "\nGenerating Random Point: ";

   XY DtL(QOfElements);

   mt19937 RandPosBase(chrono::steady_clock::now().time_since_epoch().count());
   uniform_int_distribution<int16_t> RandPos_X(-10, 10);                        //Graph limit
   uniform_int_distribution<int16_t> RandPos_Y(-17, 23);                        //Graph limit

   for (uint16_t IIt = 0; IIt < QOfElements; ++IIt) {
       DtL[IIt].emplace_back(RandPos_X(RandPosBase));
       DtL[IIt].emplace_back(RandPos_Y(RandPosBase));
   }

   cout << " done.";

   return DtL;
}

XY CopyThe15FirstPointsFrom(const XYR2LearnWith& xyr) {
   const uint16_t TotPoints = 15;
   XY xy;

   for (uint16_t xy_r = 0; xy_r < (CriticalPoints.size() > xyr.size() ? CriticalPoints.size() : xyr.size()) &&
                           xy_r < TotPoints;
                         ++xy_r)
        xy.push_back(xyr[xy_r].first);

   return xy;
}

XYR2LearnWith GenerateAndPrintTrainingPoints(const uint16_t QOfTrainingPoints, const TargetFunction& TargetF, const AxonActFunction& ActFunction) {
              XY xy = GenerateRandomPoints((QOfTrainingPoints - CriticalPoints.size() < 75) ? 75 : (QOfTrainingPoints - CriticalPoints.size()) );
              CriticalPoints.InsertInto(xy);

              XYR2LearnWith xyr;
              for (auto x_y : xy)
                  xyr.emplace_back(x_y, ActFunction(TargetF(x_y)));

              cout << "Print the Training Points\n";
              for (uint16_t xy_r = 0; xy_r < xyr.size(); ++xy_r) {
                  if (xy_r == CriticalPoints.size())
                     cout << "\n" << string(40, '-') << "End of critical points";

                  ShowPoint(xyr[xy_r].first[0], xyr[xy_r].first[1], xyr[xy_r].second);
              }

              return xyr;
}

void ShowPoint(int16_t dedriteX, int16_t dedriteY, AxonResult Position, optional<AxonResult> Result) {
     cout << "\nX: " << setw(3) << dedriteX
          <<  " Y: " << setw(3) << dedriteY
          <<  " => " << (Position > 0.0 ? "over ":"below");

     if (Result != nullopt)
        cout << (Position == Result.value()? " Passed" : "\tFailed");
}

void PrintResults(uint16_t Pos, const XY& xy, AxonResult Guess, const XYR2LearnWith& Target) {
     if (Pos == CriticalPoints.size())
        cout << "\n" << string(40, '-') << "End of critical points";

     ShowPoint(xy[Pos][0],          //X
               xy[Pos][1],          //Y
               Guess,               //Guess
               Target[Pos].second);
}
