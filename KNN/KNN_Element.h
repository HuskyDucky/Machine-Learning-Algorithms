/**
    File    : KNN_Element.h
    Author  : Menashe Rosemberg
    Created : 2019.05.10            Version: 20190510.5

    Element to k-NN classification

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
#ifndef KNNELEMENT_H
#define KNNELEMENT_H

#include <array>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

namespace knn_Element {
          constexpr uint8_t NCHARACT = 4;

          struct info {
                 info(array<double, NCHARACT> characteristics, string ClassDesc) : Characteristics(characteristics),
                                                                                   Class_Desc(ClassDesc) {}

                string getClass() const { return Class_Desc; }
                double getCharact(const uint8_t NCHARACT) const { return Characteristics[NCHARACT]; }

                private:
                    array<double, NCHARACT> Characteristics;
                    string Class_Desc;
          };
}

using ElementList = vector<knn_Element::info>;

#endif // KNNELEMENT_H
