/**
    File    : Genetic_DNA.h
    Author  : Menashe Rosemberg
    Created : 2019.03.14            Version: 20190314.1

    Genetic Algorithm

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef GENETIC_DNA_H
#define GENETIC_DNA_H

#include <chrono>
#include <random>
#include <string>

using namespace std;

using DNASizeType = uint16_t;
using GenesType = string;

struct DNA {
       DNA(GenesType genes, const float mutationrate);
       DNA(const DNASizeType DNASize, const float mutationRate);

    GenesType Genes;
    float fitness;

    GenesType Crossover(const DNA& Partner);

    private:
        mt19937 RandBase;

        bernoulli_distribution Mutation;

        inline char GenGene();
        void MutateChild(GenesType& ChildGenes);
};

#endif // GENETIC_DNA_H
