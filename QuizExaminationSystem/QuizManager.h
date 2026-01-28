#pragma once
#include <vector>
#include "Quiz.h"

using namespace std;
class QuizManager {
private:
    vector<Quiz> quizzes;

public:
    void createQuiz(const Quiz& q);
    vector<Quiz> getPublishedQuizzes() const;
    Quiz* findQuizByID(int id);
};
