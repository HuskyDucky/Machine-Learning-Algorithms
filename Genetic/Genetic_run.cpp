/**
    File    : Genetic_run.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.14            Version: 20190314.1

    Genetic Algorithm

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include <iostream>
#include <iomanip>

#include "Genetic.h"

void ShowData(const string Genes) {
     cout << '\r' << Genes; }

void Run_Genetic_Algorithm() {

    string Txt2Discover = "To be, or not to be, that is the question.";
    float MutationRate = 0.01;
    uint16_t PopTotal = 200;

    cout << "\nText to Find : " << Txt2Discover
         << "\nMutation Rate: " << (MutationRate * 100) << '%'
         << "\nPopulation   : " << PopTotal
         << "\n\n";

    Population population;
    Solution S = population.Evolve(Txt2Discover, MutationRate, PopTotal, ShowData);

    cout << '\r' << S.Genes
         << "\n\nSolution found in " << S.Generations << " generations.";
}

