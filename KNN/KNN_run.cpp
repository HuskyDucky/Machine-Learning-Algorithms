/**
    File    : KNN_run.h
    Author  : Menashe Rosemberg
    Created : 2019.05.16            Version: 20190516.1

    k-Nearest Neighbors algorithm - k-NN - Classification

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "KNN_Class.h"
#include "KNN_ReadElements.h"

void Run_KNN() {
    ElementList Elements2Test = knn_ReadElements("KNN/knn_Data2Test.txt");

    KNN knn;
    cout << "Create knn:" << endl;

    knn.Training("KNN/knn_DataBase.txt");

    cout << "Training:" << endl;

    for (ElementList::size_type IIt = 0; IIt < Elements2Test.size(); ++IIt) {
        cout << "Classify element " << IIt;
        knn.ClassifySample(Elements2Test[IIt]);
    }

    cout << knn.Hits() << " hits of " << knn.nElements_Tested() << " elements tested.\n";
}
