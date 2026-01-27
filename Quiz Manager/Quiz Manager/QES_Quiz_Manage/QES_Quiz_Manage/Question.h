#pragma once
#include "Answer.h"
#include <vector>
#include <String>
#include <iostream>
using namespace std;

class Question
{
private:
	int questionID;
	string text;
	vector<Answer> answers;

	int findAnswerIndex(int answerID) const;

public:
	Question(int id, string t);
	int getQuestionID() const;
	string getText() const;
	void addAnswer(const Answer& a);
	void markAnswerCorrect(int answerID, bool isCorrect);
	const vector<Answer>& getAnswers() const;
	void display() const;
};