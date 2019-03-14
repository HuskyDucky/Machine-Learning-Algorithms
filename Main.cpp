/**
    File    : Main.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.02            Version: 20190314.1

    Construct a simple question and wait the answer

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/

void Run_Genetic_Algorithm();

#include <vector>
#include "_lib_/Ask_Menu.h"

int main() {

    ListOfAnswers Options
                    {{"Genetic Algorithm", [](){ Run_Genetic_Algorithm(); }}
    } ;

    Ask_Menu TheQuestion("\n\nChoose the Algorithm you are learning:\n", move(Options));
    TheQuestion.Show();

    return 0;
}
