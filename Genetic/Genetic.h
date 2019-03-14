/**
    File    : Genetic.h
    Author  : Menashe Rosemberg
    Created : 2019.03.14            Version: 20190314.1

    Genetic Algorithm

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef GENETIC_H
#define GENETIC_H

#include <functional>

#include "Genetic_DNA.h"

using namespace std;

using DNAList  = vector<DNA>;

struct Solution {
       Solution(const uint32_t Gen, GenesType G) : Generations(Gen), Genes(G) {}
       uint32_t Generations;
       GenesType Genes;
};

constexpr float PerfectMatch = 1;

struct Population {
       Population();

    Solution Evolve(const GenesType& dTarget, const float mutationRate, const uint16_t QOfDNAs, const function<void(GenesType)>& ShowBestGenes);

    private:
        mt19937 RandBase;

        uint32_t Generation;
        GenesType Target;
        GenesType::size_type TargetSize;
        float MutationRate;
        DNAList PopulationDNA;
        DNAList::size_type PopulationSize;
        DNAList Matings;
        float NormalizeFitnessBase;
        GenesType Match;

        void CalcFitness(DNA& Individual);

        void CreatePopulation();
        void NaturalSelection();
        void RiseNewGeneration();
};
#endif // GENETIC_H
