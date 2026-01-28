#pragma once
#include <string>
#include <vector>
#include "Answer.h"

using namespace std;
class Question {
private:
    string content;
    vector<Answer> answers;

public:
    Question(const string& content = "");

    void addAnswer(const Answer& ans);
    string getContent() const;
    const vector<Answer>& getAnswers() const;
};
