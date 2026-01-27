#pragma once
#include <String>
#include <iostream>
using namespace std;

class Answer
{
private:
	int answerID;
	string text;
	bool isCorrect;

public:
	Answer(int id, string t, bool correct = false);
	int getAnswerID() const;
	string getText() const;
	bool getIsCorrect() const;
	void setIsCorrect(bool correct);
	void display() const;
};