#pragma once
#include <string>
using namespace std;
class Answer {
private:
    string content;
    bool isCorrect;

public:
    Answer(const string& content = "", bool correct = false);

    string getContent() const;
    bool getIsCorrect() const;
};
