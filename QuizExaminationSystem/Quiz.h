#pragma once
#include <string>
#include <vector>
#include "Question.h"

using namespace std;
class Quiz {
private:
    int quizID;
    std::string title;
    int timeLimit; // minutes
    bool published;
    std::vector<Question> questions;

public:
    Quiz(int id = 0, const std::string& title = "", int timeLimit = 0);

    void addQuestion(const Question& q);
    void publish();

    int getID() const;
    string getTitle() const;
    int getTimeLimit() const;
    bool isPublished() const;
    const std::vector<Question>& getQuestions() const;
};
