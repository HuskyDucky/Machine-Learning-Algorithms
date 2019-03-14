/**
    File    : Ask_Menu.h
    Author  : Menashe Rosemberg
    Created : 2019.03.08            Version: 20190308.2.1

    Construct a Menu based on Ask
    Menashe Rosemberg   Israel +972-52-323-0538
    Copyright(c) 2019      All rights reserved.

    Software distributed under the MIT License is distributed on an "AS IS" BASIS,
    NO WARRANTIES OR CONDITIONS OF ANY KIND, explicit or implicit.
**/
#ifndef ASK_MENU_H
#define ASK_MENU_H

#include <functional>

#include "Ask.h"

using ListOfAnswers = vector<pair<string, function<void()>>>;

struct Ask_Menu : protected Ask {
       Ask_Menu(const string& Question, ListOfAnswers&& OptionFunction);

    void Show();

    private:
        vector<function<void()>> Func;

        uint8_t DecodeLetter(uint8_t letter);
};

#endif // ASK_MENU_H
