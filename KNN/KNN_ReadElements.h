/**
    File    : KNN_ReadElements.h
    Author  : Menashe Rosemberg
    Created : 2019.05.15            Version: 20190515.1

    k-Nearest Neighbors algorithm - k-NN - Read elements from file

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef KNN_READ_H
#define KNN_READ_H

#include <fstream>
#include <iostream>
#include <filesystem>

#include "KNN_Element.h"

namespace fs = std::filesystem;

ElementList knn_ReadElements(const string& FileName);

#endif // KNN_READ_H
