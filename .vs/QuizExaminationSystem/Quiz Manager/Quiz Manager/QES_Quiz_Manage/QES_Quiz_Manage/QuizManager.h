#pragma once
#include "Quiz.h"
#include <vector>
using namespace std;
/* Class: QuizManager
   Used to:
     - Handle all quiz management operations
     - Act as a bridge between user menu and quiz objects */
class QuizManager
{
private:
    vector<Quiz> quizzes; //Store all quizzes
    int findQuizIndex(int quizID); //Find quiz index by quiz ID

public:
    // Use Case : Manage Quiz
    void createQuiz();
    void updateQuiz();
    void deleteQuiz();
    void publishQuiz();

    //Use case: Configure Quiz Settings
    void setQuizTimeLimit();
    void setScoringRules();

    void listQuizzes(); //Untility function

    // Use Case: Manage Question & Answer
    void createQuestion(); // Add question to a quiz
    void addAnswerToQuestion(); // Add answer to a question in a quiz
    void markAnswerCorrect(); // Mark/unmark an answer as correct
    void listQuestionsInQuiz(); // List questions and answers in a quiz
};