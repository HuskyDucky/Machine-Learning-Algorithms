/**
    File    : Neuron_Abort.h
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190320.2

    Neuron Abort Message

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef NEURON_ABORT_H
#define NEURON_ABORT_H

#include <iostream>

namespace WRONG {
          constexpr uint8_t QUANTITYofDEDRITES  = 0;
          constexpr uint8_t QUANTITYofDATA      = 1;
}

namespace ABORT {

          void BecauseOf(const uint8_t MsGO) {

               std::cerr << "\n\nNeuron: ";

               switch (MsGO) {
                   case WRONG::QUANTITYofDEDRITES: std::cerr << "Every neuron needs at least two Dedrites.\n\n"; break;
                   case WRONG::QUANTITYofDATA    : std::cerr << "Quantity of DATA are not correct.\n\n"; break;
               }

               abort();
          }
}
#endif // NEURON_ABORT_H
