#pragma once
#include <string>
#include <vector>
#include "Question.h"

class Quiz {
private:
    int id;
    std::string title;
    int timeLimit;  
    double scorePerQuestion;
    bool published;
    std::vector<Question> questions;

    int findQuestionIndex(int qid) const;

public:
    Quiz(int id = 0, const std::string& t = "");

    int getId() const;
    std::string getTitle() const;
    bool isPublished() const;
    int getTimeLimit() const;
    double getScorePerQuestion() const;
    const std::vector<Question>& getQuestions() const;

    void addQuestion(const Question& q);
    void addAnswerToQuestion(int qid, const Answer& a);
    void markCorrectAnswer(int qid, int aid);

    void setTimeLimit(int minutes);
    void setScorePerQuestion(double s);
    void publish();
};
