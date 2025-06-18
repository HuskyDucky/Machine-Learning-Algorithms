/**
    File    : Main.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190516.4

    Construct a simple question and wait the answer

    Copyright (c) 2019 HuskyDucky (Menashe Rosemberg) rosemberg@ymail.com

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

void Run_Genetic_Algorithm();
void Run_KNN();
void Run_Perceptron();
void Run_Neural_Network();
void Run_Neural_Network_T2();

#include <vector>
#include "_lib_/Ask_Menu.h"

int main() {

    ListOfAnswers Options
                    {{"Genetic Algorithm",                      [](){ Run_Genetic_Algorithm(); }},
                     {"k-Nearest Neighbors Algorithm",          [](){ Run_KNN(); }},
                     {"Perceptron",                             [](){ Run_Perceptron(); }},
//                     {"Neural Network - Gradient Descent",      [](){ Run_Neural_Network(); }},
                     {"Neural Network - Eta Grad and Momentum", [](){ Run_Neural_Network_T2(); }}
    };

    Ask_Menu TheQuestion("\n\nChoose the Algorithm you are learning:\n", move(Options));
    TheQuestion.Show();

    return 0;
}
