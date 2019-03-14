/**
    File    : Genetic.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.14            Version: 20190314.1

    Genetic Algorithm

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Genetic.h"

Population::Population() :  RandBase(chrono::steady_clock::now().time_since_epoch().count()),
                            Generation(0),
                            Target(""),
                            TargetSize(0),
                            MutationRate(0.0),
                            PopulationDNA({}),
                            PopulationSize(0),
                            Matings({}),
                            NormalizeFitnessBase(0.0),
                            Match("") {}

Solution Population::Evolve(const GenesType& dTarget, const float mutationRate, const uint16_t QOfDNAs, const function<void(GenesType)>& ShowBestGenes) {
     this->Generation = 0;
     this->Target = dTarget;
     this->TargetSize = dTarget.size();
     this->PopulationSize = QOfDNAs;
     this->PopulationDNA.clear();
     this->PopulationDNA.reserve(QOfDNAs);
     this->MutationRate = mutationRate;
     this->NormalizeFitnessBase = 0.0;

     this->CreatePopulation();

     for (;;) {
         this->NaturalSelection();
         ShowBestGenes(this->Match);

         if (this->Match == dTarget)
            break;

         this->RiseNewGeneration();
     }


     return Solution(this->Generation, move(this->Match));
}

void Population::CreatePopulation() {
     for (uint16_t IndividualN = 0; IndividualN < PopulationSize; ++IndividualN) {
         this->PopulationDNA.emplace_back(this->Target.size(), this->MutationRate);
         this->CalcFitness(this->PopulationDNA.back());
     }
}

void Population::CalcFitness(DNA& Individual) {     //Check how close this genes are to target
      float Score = 0;

      for (string::size_type Letter = 0; Letter < TargetSize; ++Letter)
          if (Individual.Genes[Letter] == this->Target[Letter])
             Score++;

      Individual.fitness = Score / static_cast<float>(TargetSize);

      this->NormalizeFitnessBase += Individual.fitness;
}

void Population::NaturalSelection() {
     this->Matings.clear();
     this->NormalizeFitnessBase /= PopulationSize;

     float BestFitness = 0.0;
     for (DNAList::size_type Ind = 0; Ind < PopulationSize; ++Ind) {
         if (this->PopulationDNA[Ind].fitness > BestFitness) {          //Evaluate the Genes
            this->Match =  this->PopulationDNA[Ind].Genes;

            if (this->PopulationDNA[Ind].fitness == 1.0)
                break;

            BestFitness = this->PopulationDNA[Ind].fitness;
         }

         uint16_t WeightTimes = this->PopulationDNA[Ind].fitness / this->NormalizeFitnessBase;  //Normalize fitness
                  for (uint8_t AddDNA = 0; AddDNA < WeightTimes; ++AddDNA)                      //Best Genes are more likely to be added
                      this->Matings.emplace_back(this->PopulationDNA[Ind]);
    }
}

void Population::RiseNewGeneration() {
     this->PopulationDNA.clear();
     this->NormalizeFitnessBase = 0.0;

     const DNAList::size_type MatingSize = this->Matings.size() - 1;

     if (MatingSize == numeric_limits<DNAList::size_type>::max())
        this->CreatePopulation();                                   //No survivors. Create a new Generation
     else
         for (DNAList::size_type Ind = 0; Ind < PopulationSize; ++Ind) {
              DNA& Mother = this->Matings[uniform_int_distribution<DNAList::size_type>(0, MatingSize)(this->RandBase)];
              DNA& Father = this->Matings[uniform_int_distribution<DNAList::size_type>(0, MatingSize)(this->RandBase)];

              this->PopulationDNA.emplace_back(Mother.Crossover(Father), this->MutationRate);   //Child is added

              this->CalcFitness(this->PopulationDNA.back());
         }

    this->Generation++;
}
