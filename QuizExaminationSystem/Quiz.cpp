#include "Quiz.h"
using namespace std;

Quiz::Quiz(int id, const string& t)
    : id(id), title(t), timeLimit(10), scorePerQuestion(1.0), published(false) {
}

int Quiz::getId() const { return id; }
string Quiz::getTitle() const { return title; }
bool Quiz::isPublished() const { return published; }
int Quiz::getTimeLimit() const { return timeLimit; }
double Quiz::getScorePerQuestion() const { return scorePerQuestion; }
const vector<Question>& Quiz::getQuestions() const { return questions; }

int Quiz::findQuestionIndex(int qid) const {
    for (int i = 0; i < (int)questions.size(); i++)
        if (questions[i].getId() == qid) return i;
    return -1;
}

void Quiz::addQuestion(const Question& q) {
    questions.push_back(q);
}

void Quiz::addAnswerToQuestion(int qid, const Answer& a) {
    int idx = findQuestionIndex(qid);
    if (idx != -1) questions[idx].addAnswer(a);
}

void Quiz::markCorrectAnswer(int qid, int aid) {
    int idx = findQuestionIndex(qid);
    if (idx != -1) questions[idx].markCorrectAnswer(aid);
}

void Quiz::setTimeLimit(int minutes) {
    timeLimit = minutes;
}

void Quiz::setScorePerQuestion(double s) {
    scorePerQuestion = s;
}

void Quiz::publish() {
    published = true;
}
