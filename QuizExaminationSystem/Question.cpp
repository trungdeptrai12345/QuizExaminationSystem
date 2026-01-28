#include "Question.h"

Question::Question(int id, string t)
{
	questionID = id;
	text = t;
	answers.clear();
}

int Question::getQuestionID() const
{
	return questionID;
}

string Question::getText() const
{
	return text;
}

int Question::findAnswerIndex(int answerID) const
{
	for (int i = 0; i < static_cast<int>(answers.size()); i++)
	{
		if (answers[i].getAnswerID() == answerID)
			return i;
	}
	return -1;
}

void Question::addAnswer(const Answer& a)
{
	if (findAnswerIndex(a.getAnswerID()) != -1)
	{
		cout << "Answer with this ID already exists for this question.\n";
		return;
	}
	answers.push_back(a);
}

void Question::markAnswerCorrect(int answerID, bool isCorrect)
{
	int idx = findAnswerIndex(answerID);
	if (idx == -1)
	{
		cout << "Answer not found.\n";
		return;
	}
	answers[idx].setIsCorrect(isCorrect);
}

const vector<Answer>& Question::getAnswers() const
{
	return answers;
}

void Question::display() const
{
	cout << "  Question ID: " << questionID << endl;
	cout << "  Text: " << text << endl;
	if (answers.empty())
	{
		cout << "\tNo answers.\n";
		return;
	}
	for (const Answer& a : answers)
		a.display();
}