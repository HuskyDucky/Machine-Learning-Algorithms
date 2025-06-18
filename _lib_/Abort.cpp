/**
    File    : Abort.h
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190326.3

    Abort Messages

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
