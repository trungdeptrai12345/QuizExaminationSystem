#pragma once
#include "ResultData.h"
#include "Quiz.h"
#include <vector>

class ReviewSystem {
private:
    vector<ExamResult> database;

public:
    void startExam(const Quiz& quiz, string studentName);
    void reviewLastExam();
    void showStatistics();
};