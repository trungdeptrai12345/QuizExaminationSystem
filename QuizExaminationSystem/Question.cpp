#include "Question.h"
using namespace std;

Question::Question(int id, const string& t)
    : id(id), text(t) {
}

int Question::getId() const { return id; }
string Question::getText() const { return text; }

int Question::findAnswerIndex(int aid) const {
    for (int i = 0; i < (int)answers.size(); i++)
        if (answers[i].getId() == aid) return i;
    return -1;
}

void Question::addAnswer(const Answer& a) {
    answers.push_back(a);
}

void Question::markCorrectAnswer(int aid) {
    for (auto& a : answers) a.setCorrect(false);
    int idx = findAnswerIndex(aid);
    if (idx != -1) answers[idx].setCorrect(true);
}

const vector<Answer>& Question::getAnswers() const {
    return answers;
}
