#include "Answer.h"

Answer::Answer(const string& content, bool correct)
    : content(content), isCorrect(correct) {
}

string Answer::getContent() const {
    return content;
}

bool Answer::getIsCorrect() const {
    return isCorrect;
}
