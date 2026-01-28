#include "QuizManager.h"

void QuizManager::createQuiz(const Quiz& q) {
    quizzes.push_back(q);
}

vector<Quiz> QuizManager::getPublishedQuizzes() const {
    vector<Quiz> result;
    for (auto& q : quizzes)
        if (q.isPublished())
            result.push_back(q);
    return result;
}

Quiz* QuizManager::findQuizByID(int id) {
    for (auto& q : quizzes)
        if (q.getID() == id)
            return &q;
    return nullptr;
}
