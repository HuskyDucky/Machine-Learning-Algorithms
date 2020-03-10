/**
    File    : Ask.h
    Author  : Menashe Rosemberg
    Created : 2017.12.03            Version: 20190310.1

    Construct a simple question and wait the answer

    Copyright (c) 2019 TheArquitect (Menashe Rosemberg) rosemberg@ymail.com

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
#ifndef ASK_H
#define ASK_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define ASK_YESorNO     {"no", "yes"}

namespace ASK {
          constexpr uint8_t YESorNO_BEHAVIOR        = 0b00000010;
          constexpr uint8_t DEFAULT_BEHAVIOR        = 0b00000010;

          constexpr uint8_t SHOW_IS_CASE_IN_LOOP    = 0b00000000;
          constexpr uint8_t NOT_SHOW_ANSWERS        = 0b00000001;
          constexpr uint8_t IS_NOT_CASESENS         = 0b00000010;
          constexpr uint8_t NOT_IN_LOOP             = 0b00000100;   //wasmade() function member will returns 255 if the answer gave wasn't in Answers
          constexpr uint8_t NO_BRACKETS             = 0b00001000;

          constexpr uint8_t ANSWARE_BY_LETTERS      = 0b10000000;
}

struct Ask : public ostream {
       Ask();
       Ask(const string& TheQuestion);
       Ask(vector<string>&& aAns, uint8_t iOptions = ASK::SHOW_IS_CASE_IN_LOOP);
       Ask(const string& TheQuestion, vector<string>&& aAns, uint8_t iOptions = ASK::SHOW_IS_CASE_IN_LOOP);
      ~Ask() = default;

    void hastheAnswers(vector<string>& aAns);
    void hastheAnswers(vector<string>&& aAns);
    void hastheBehavior(uint8_t iOptions);          //use the logic '|' to set behavior: ASK::NOT_SHOW_ANSWERS | ASK::NOT_IN_LOOP
//    void AnotherQuestion();                         //Reset the class to be ready to another question

    uint8_t wasmade();                              //Make the question.

    private:
        stringbuf ssTheQuestionIs;
        vector<string> Answers = ASK_YESorNO;
        uint8_t BehaviorSet = ASK::SHOW_IS_CASE_IN_LOOP;

        struct GenLetter;

        Ask(const Ask&) = delete;
        Ask& operator=(const Ask&) = delete;
};
/*
uint8_t Ask(const string& sQuestion,
                  const vector<string>& aAnswers,
                  uint8_t iOption =    ASK::SHOW_ANSWERS);
*/
#endif // ASK_H
