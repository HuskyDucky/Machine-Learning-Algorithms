/**
    File    : KNN_Class.h
    Author  : Menashe Rosemberg
    Created : 2019.05.14            Version: 20190514.2

    k-Nearest Neighbors algorithm - k-NN - Classification

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef KNNCLASS_H
#define KNNCLASS_H

#include <set>
#include <cmath>
#include <iostream>
#include <algorithm>

#include "KNN_Element.h"
#include "KNN_ReadElements.h"

using Euclidian_Distance = double;

struct KNN {
    void Training(const string& FileName);
    void ClassifySample(const knn_Element::info& Elem);
    uint32_t Hits() const;
    uint32_t nElements_Tested() const;

    private:
        uint32_t hits = 0;
        uint32_t nElTested = 0;
        ElementList Elements;
        vector<string> Descriptions;

        void AddDescription(const string& ElDesc);
        string Classify(const knn_Element::info& Elem);

        double EuclidianDistance(knn_Element::info El1, knn_Element::info El2);
};

#endif // KNNCLASS_H
