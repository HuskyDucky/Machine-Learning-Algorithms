/**
    File    : KNN_Class.cpp
    Author  : Menashe Rosemberg
    Created : 2019.05.16            Version: 20190516.1

    k-Nearest Neighbors algorithm - k-NN - Classification

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "KNN_Class.h"

void KNN::Training(const string& FileName) {

     this->Elements = knn_ReadElements(FileName);

     for (ElementList::size_type IIt = 0; IIt < this->Elements.size(); ++IIt)
         this->AddDescription(this->Elements[IIt].getClass());
}

void KNN::AddDescription(const string& ElDesc) {
     for (uint8_t IIt = 0; IIt < this->Descriptions.size(); ++IIt)
         if (this->Descriptions[IIt] == ElDesc)
            return;

     this->Descriptions.emplace_back(ElDesc);
}

void KNN::ClassifySample(const knn_Element::info& Elem) {
     string Desc = this->Classify(Elem);

     cout << "\n\tExpected Class: " << Elem.getClass();
     cout << "\n\tResulted Class: " << Desc << "\n\n";

     if (Elem.getClass() == Desc)
        this->hits++;

     this->nElTested++;
}

string KNN::Classify(const knn_Element::info& newEl) {
       set<pair<Euclidian_Distance, ElementList::size_type>> Distances;       //related to element tested

       for (uint32_t IIt = 0; IIt < this->Elements.size(); IIt++)
            Distances.emplace(this->EuclidianDistance(Elements[IIt], newEl), IIt);

       vector<uint32_t> QuantNearClasses(this->Descriptions.size());        //to count which near classes is more frequent

       int16_t nKNN = QuantNearClasses.size() + 1;                          //number of nearest neighbors to check. It is always the quantity. I used Pigeonhole principle
                                                                            //to avoid a tie situation
       for (auto Dis = Distances.cbegin(); Dis != Distances.cend(); ++Dis) {
           for (uint16_t Desc = 0; Desc < Descriptions.size(); ++Desc)
               if (Descriptions[Desc] == Elements[Dis->second].getClass()) {
                   QuantNearClasses[Desc]++;
                   break;
               }

           if (--nKNN >= 0) break;
       }

       return this->Descriptions[
                                 distance(QuantNearClasses.cbegin(),
                                          max_element(QuantNearClasses.cbegin(), QuantNearClasses.cend())
                                 )
                    ];
}

double KNN::EuclidianDistance(knn_Element::info El1, knn_Element::info El2) {
       double Sum = 0;

       for (uint8_t NCh = 0; NCh < knn_Element::NCHARACT; ++NCh)
           Sum += pow(El1.getCharact(NCh) - El2.getCharact(NCh), 2);

       return sqrt(Sum);
}

uint32_t KNN::Hits() const { return this->hits; }
uint32_t KNN::nElements_Tested() const { return this->nElTested; }
