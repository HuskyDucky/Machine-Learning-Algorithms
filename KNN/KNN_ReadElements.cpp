/**
    File    : KNN_ReadElements.cpp
    Author  : Menashe Rosemberg
    Created : 2019.05.15            Version: 20190515.2

    k-Nearest Neighbors algorithm - k-NN - Read elements from file

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
