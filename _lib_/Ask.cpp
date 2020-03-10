/**
    File    : Ask.cpp
    Author  : Menashe Rosemberg
    Created : 2017.12.03            Version: 20181111.3

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
#include "Ask.h"

Ask::Ask() : ostream(&this->ssTheQuestionIs) {}

Ask::Ask(vector<string>&& aAns, uint8_t iOptions)
        : ostream(&this->ssTheQuestionIs), Answers(aAns), BehaviorSet(iOptions) {}

Ask::Ask(const string& TheQuestion)
        : ostream(&this->ssTheQuestionIs) {
        ssTheQuestionIs.sputn(TheQuestion.c_str(), TheQuestion.size());
}

Ask::Ask(const string& TheQuestion, vector<string>&& aAns, uint8_t iOptions)
        : ostream(&this->ssTheQuestionIs), Answers(aAns), BehaviorSet(iOptions) {
        ssTheQuestionIs.sputn(TheQuestion.c_str(), TheQuestion.size());
}

void Ask::hastheAnswers(vector<string>& aAns) {
     this->Answers = aAns;
}

void Ask::hastheAnswers(vector<string>&& aAns) {
     this->Answers = aAns;
}

void Ask::hastheBehavior(uint8_t iOptions) {
     this->BehaviorSet = iOptions;
}

/*void Ask::AnotherQuestion() {
     this->Answers = {};
     this->BehaviorSet = ASK::SHOW_ANSWERS;
     this->ssTheQuestionIs.str("");
}*/

struct Ask::GenLetter {
       char letter() {
            switch (Letter) {
                case 123: return (65);
                case  91: return (48);
                case  58: return '*';
                default: if (Letter != '*')
                            ++Letter;
            }

            return Letter;
        }

    private:
        char Letter = 96;
};

uint8_t Ask::wasmade() {
        char BracketL[] = "\n\t[";
        char BracketR[] = "]";

        if (this->BehaviorSet & ASK::NO_BRACKETS)
            BracketL[2] = BracketR[0] = ' ';


        if (this->BehaviorSet & ASK::ANSWARE_BY_LETTERS) {
            GenLetter Next;

            for (auto& IIt : this->Answers)
                if (IIt.compare(1, 2, "- ") != 0) {
                    IIt.insert(0, " - ");
                    IIt[0] = Next.letter();
                }
        }

        for (;;) {
            cout << this->ssTheQuestionIs.str();

            if (!(this->BehaviorSet & ASK::NOT_SHOW_ANSWERS))
                for (auto& IIt : this->Answers)
                    cout << BracketL << IIt << BracketR;

            cout << "\n: ";

            string sAux;
            getline(cin, sAux);

            if (this->BehaviorSet & ASK::IS_NOT_CASESENS)
               transform(sAux.begin(), sAux.end(), sAux.begin(), ::tolower);

            if (this->BehaviorSet & ASK::ANSWARE_BY_LETTERS) {
               for (auto& IIt : this->Answers)
                   if (sAux[0] == IIt[0])
                      return sAux[0];

            } else {
                auto IIt = find(this->Answers.cbegin(), this->Answers.cend(), sAux);

                if (IIt != this->Answers.cend()) {
                   this->ssTheQuestionIs.str("");
                   return IIt - this->Answers.cbegin();
                }
            }

            if (this->BehaviorSet & ASK::NOT_IN_LOOP) {
               this->ssTheQuestionIs.str("");
               return 255;
            }

            cout << "\nIt is not an option.\n\n";
        }
}
