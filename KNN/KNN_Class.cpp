/**
    File    : KNN_Class.cpp
    Author  : Menashe Rosemberg
    Created : 2019.05.16            Version: 20190516.1

    k-Nearest Neighbors algorithm - k-NN - Classification

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
