#pragma once
#include <string>

class Answer {
private:
    int id;
    std::string text;
    bool correct;

public:
    Answer(int id = 0, const std::string& t = "", bool c = false);

    int getId() const;
    std::string getText() const;
    bool isCorrect() const;
    void setCorrect(bool c);
};
