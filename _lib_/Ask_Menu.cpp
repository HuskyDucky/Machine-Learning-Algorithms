/**
    File    : Ask_Menu.cpp
    Author  : Menashe Rosemberg
    Created : 2019.03.08            Version: 20190308.2

    Construct a Menu based on Ask

    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
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

