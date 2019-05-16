/**
    File    : KNN_Element.h
    Author  : Menashe Rosemberg
    Created : 2019.05.10            Version: 20190510.4

    Element to k-NN classification

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef KNNELEMENT_H
#define KNNELEMENT_H

#include <array>
#include <vector>
#include <string>

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
