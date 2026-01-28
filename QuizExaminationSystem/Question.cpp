#include "Question.h"

Question::Question(const string& content) : content(content) {}

void Question::addAnswer(const Answer& ans) {
    answers.push_back(ans);
}

std::string Question::getContent() const {
    return content;
}

const vector<Answer>& Question::getAnswers() const {
    return answers;
}
