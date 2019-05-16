/**
    File    : KNN_ReadElements.cpp
    Author  : Menashe Rosemberg
    Created : 2019.05.15            Version: 20190515.2

    k-Nearest Neighbors algorithm - k-NN - Read elements from file

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "KNN_ReadElements.h"

ElementList knn_ReadElements(const string& FileName) {
    ElementList Elements2Test;

    if (fs::exists(FileName)) {
        ifstream fFile(FileName);

        if (fFile.good()) {
            array<double, knn_Element::NCHARACT> Characts;
            string Description;

            while (!fFile.eof()) {
                  for (uint8_t NCh = 0; NCh < knn_Element::NCHARACT; ++NCh)
                      fFile >> Characts[NCh];
                  fFile >> Description;

                  Elements2Test.emplace_back(Characts, Description);
            }
        } else {
          cerr << "I couldn't read the file " << FileName << ".";
          abort();
        }
     } else {
       cerr << "File " << FileName << " doesn't exist.\n" << endl;
       abort();
     }

     return Elements2Test;
}
