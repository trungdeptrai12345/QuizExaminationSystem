#include "Quiz.h"

Quiz::Quiz(int id, const string& title, int timeLimit)
    : quizID(id), title(title), timeLimit(timeLimit), published(false) {
}

void Quiz::addQuestion(const Question& q) {
    questions.push_back(q);
}

void Quiz::publish() {
    published = true;
}

int Quiz::getID() const { return quizID; }
string Quiz::getTitle() const { return title; }
int Quiz::getTimeLimit() const { return timeLimit; }
bool Quiz::isPublished() const { return published; }

const vector<Question>& Quiz::getQuestions() const {
    return questions;
}
