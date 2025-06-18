/**
    File    : Genetic.h
    Author  : Menashe Rosemberg
    Created : 2019.03.14            Version: 20190314.1

    Genetic Algorithm

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
