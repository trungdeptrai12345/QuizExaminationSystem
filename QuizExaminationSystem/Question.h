#pragma once
#include <string>
#include <vector>
#include "Answer.h"

class Question {
private:
    int id;
    std::string text;
    std::vector<Answer> answers;

    int findAnswerIndex(int aid) const;

public:
    Question(int id = 0, const std::string& t = "");

    int getId() const;
    std::string getText() const;

    void addAnswer(const Answer& a);
    void markCorrectAnswer(int aid);
    const std::vector<Answer>& getAnswers() const;
};
