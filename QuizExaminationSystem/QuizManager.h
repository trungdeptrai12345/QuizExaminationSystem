#pragma once
#include <vector>
#include "Quiz.h"

using namespace std;
/*
QuizManager
Manage Quiz
Manage Question
Configure Quiz Settings
*/
class QuizManager {
private:
    vector<Quiz> quizzes;
    int findQuizIndex(int id) const;

public:
    void createQuiz();
    void deleteQuiz();
    void listAllQuizzes() const;
    void publishQuiz();

    void setQuizTimeLimit();
    void setScorePerQuestion();

    void addQuestion();
    void addAnswer();
    void markCorrectAnswer();

    vector<Quiz> getPublishedQuizzes() const;
    Quiz* getQuizById(int id);
};
