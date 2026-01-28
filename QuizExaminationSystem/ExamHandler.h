#pragma once
#include "QuizManager.h"
#include "ResultData.h"

/*
ExamHandler
Take Quiz
Submit Quiz
Auto Grading
*/
class ExamHandler {
public:
    ExamResult takeQuiz(const Quiz& quiz, const std::string& studentName);
};
