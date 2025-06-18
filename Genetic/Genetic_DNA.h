/**
    File    : Genetic_DNA.h
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
