/**
    File    : Abort.h
    Author  : Menashe Rosemberg
    Created : 2019.03.17            Version: 20190326.1

    Abort Messages

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef ABORT_H
#define ABORT_H

#include <iostream>

namespace WRONG {
          constexpr uint8_t QUANTITYofDEDRITES          = 0;
          constexpr uint8_t QUANTITYofDATA              = 1;
          constexpr uint8_t QUANTITYofLAYERS            = 10;
          constexpr uint8_t QUANTITYofINFORMATION       = 11;
          constexpr uint8_t QUANTITYofRESULTSEXPECTED   = 12;
}

namespace ABORT {
          void BecauseOf(const uint8_t MsGO);
}
#endif // ABORT_H
