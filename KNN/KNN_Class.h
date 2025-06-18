/**
    File    : KNN_Class.h
    Author  : Menashe Rosemberg
    Created : 2019.05.14            Version: 20190514.2

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
