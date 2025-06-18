/**
    File    : Ask_Menu.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.08            Version: 20190308.2

    Construct a Menu based on Ask

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
#include "Ask_Menu.h"

Ask_Menu::Ask_Menu(const string& Question, ListOfAnswers&& OptionFunction) : Ask(Question) {

    vector<string> Options; Options.reserve(OptionFunction.size());
    this->Func.reserve(OptionFunction.size());

    for (auto& OpF : OptionFunction) {
        Options.push_back(OpF.first);
        this->Func.push_back(OpF.second);
    }

    Options.emplace_back("Exit");

    Ask::hastheAnswers(Options);
    Ask::hastheBehavior(ASK::ANSWARE_BY_LETTERS | ASK::NO_BRACKETS);
}

void Ask_Menu::Show() {
    for (;;) {
        uint8_t Answer = this->DecodeLetter(Ask::wasmade());

        if (Answer == Func.size())
            break;

        Func[Answer]();

    }
}


uint8_t Ask_Menu::DecodeLetter(uint8_t letter) {
        if (letter > 96)
             return letter - 97;
        else if (letter > 64)
             return letter - 65;

        return letter - 48;
}

