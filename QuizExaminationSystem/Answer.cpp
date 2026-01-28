#include "Answer.h"
using namespace std;

Answer::Answer(int id, const string& t, bool c)
    : id(id), text(t), correct(c) {
}

int Answer::getId() const { return id; }
string Answer::getText() const { return text; }
bool Answer::isCorrect() const { return correct; }
void Answer::setCorrect(bool c) { correct = c; }
