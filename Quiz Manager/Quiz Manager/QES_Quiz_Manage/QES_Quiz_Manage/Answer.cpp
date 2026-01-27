#include "Answer.h"

Answer::Answer(int id, string t, bool correct)
{
	answerID = id;
	text = t;
	isCorrect = correct;
}

int Answer::getAnswerID() const
{
	return answerID;
}

string Answer::getText() const
{
	return text;
}

bool Answer::getIsCorrect() const
{
	return isCorrect;
}

void Answer::setIsCorrect(bool correct)
{
	isCorrect = correct;
}

void Answer::display() const
{
	cout << "\tAnswer ID: " << answerID << " | " << text << " | "
		<< (isCorrect ? "Correct" : "Incorrect") << endl;
}