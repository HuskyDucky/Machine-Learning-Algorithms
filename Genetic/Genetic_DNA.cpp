/**
    File    : Genetic_DNA.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.14            Version: 20190314.1

    Genetic Algorithm

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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
