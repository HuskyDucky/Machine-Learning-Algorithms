/**
    File    : Abort.h
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190326.3

    Abort Messages

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#include "Abort.h"

void ABORT::BecauseOf(const uint8_t MsGO) {
     if (MsGO >= 10)
        std::cerr << "\n\nNeural Network: ";
     else
        std::cerr << "\n\nNeuron: ";

     switch (MsGO) {
            case WRONG::QUANTITYofDEDRITES          : std::cerr << "Every neuron needs at least two Dedrites."; break;
            case WRONG::QUANTITYofLAYERS            : std::cerr << "Minimum of Layers is three"; break;
            case WRONG::QUANTITYofRESULTSEXPECTED   : std::cerr << "Quantity of Results Expected passed are not correct"; break;
            default                                 : std::cerr << "Quantity of DATA are not correct.";
     }

     std::cerr << '\n' << std::endl;

     abort();
}
