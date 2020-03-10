/**
    File    : Genetic_DNA.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.14            Version: 20190314.1

    Genetic Algorithm

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
#include "Genetic_DNA.h"

DNA::DNA(GenesType genes, const float mutationRate) : Genes(move(genes)),
                                                      RandBase(chrono::steady_clock::now().time_since_epoch().count()),
                                                      Mutation(mutationRate) {}

DNA::DNA(const DNASizeType DNASize, const float mutationRate) : RandBase(chrono::steady_clock::now().time_since_epoch().count()),
                                                                Mutation(mutationRate) {
    for (DNASizeType DNAST = 0; DNAST < DNASize; ++DNAST)
        this->Genes.push_back(GenGene());
}

inline char DNA::GenGene() {
       return uniform_int_distribution<char>(32, 126)(RandBase);
}

GenesType DNA::Crossover(const DNA& Partner) {
          const GenesType::size_type GeneSize = Partner.Genes.size();
          GenesType Child;

          GenesType::size_type midpoint = uniform_int_distribution<GenesType::size_type>(0, Partner.Genes.size()-1)(RandBase); // Pick a random midpoint

          for (GenesType::size_type GeneN = 0; GeneN < GeneSize; ++GeneN)
              Child.push_back(GeneN > midpoint?
                              this->Genes[GeneN]: Partner.Genes[GeneN]);

          this->MutateChild(Child);

          return Child;
}

void DNA::MutateChild(GenesType& ChildGenes) {

     for (GenesType::size_type GeneN = 0; GeneN < ChildGenes.size(); ++GeneN)
         if (Mutation(RandBase))
            ChildGenes[GeneN] = GenGene();
}
