#pragma once
#include <vector>
#include "ResultData.h"

/*
ReviewSystem
View Result
Review Answer
Teacher View Student Result
*/
class ReviewSystem {
private:
    std::vector<ExamResult> results;

public:
    void saveResult(const ExamResult& r);
    void reviewLastResult() const;
    void viewAllResults() const;
};
