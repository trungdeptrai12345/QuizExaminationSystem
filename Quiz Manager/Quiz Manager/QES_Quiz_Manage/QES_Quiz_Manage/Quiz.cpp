#include "Quiz.h"
#include <iostream>
using namespace std;


Quiz::Quiz(int id, string t, string d)
{
	quizID = id; //Asign quiz ID from input parameter
	title = t; //Asign quiz title
	description = d;//Assign quiz description
	timeLimit = 0; //Default: no time limit
	isPublished = false; //Default: not published
	scorePerQuestion = 1.0; // Default score
}
void Quiz::updateQuiz(string t, string d)
{
	title = t; //Update title with new value
	description = d; //Update description with new value
}
void Quiz::publishQuiz()
{
	isPublished = true;// Set quiz status to published
}
void Quiz::setTimeLimit(int minutes)
{
	timeLimit = minutes;// Assign new time limit value
}
void Quiz::setScoringRules(double score)
{
	scorePerQuestion = score;// Assign new score per question 
}
void Quiz::display() const
{
	cout << "Quiz ID: " << quizID << endl; //Print quizID
	cout << "Title: " << title << endl; //Print quiz title
	cout << "Description: " << description << endl;//Print quiz description
	cout << "Time Limit: " << timeLimit << " minutes" << endl;//Print time limit
	cout << "Score per question: " << scorePerQuestion << endl;//Print score per question
	cout << "Published: " << (isPublished ? "Yes" : "No") << endl;//Print published status
}
int Quiz::getQuizID() const
{
	/* Used to:
	 - Search Quiz.
	 - Identify Quiz
	 - Manage Quiz list */
	return quizID;
}
bool Quiz::getStatus() const
{
	/* Used to:
	 - Prevent student form taking unpublished quiz
	 - Validate quiz availability */
	return isPublished;
}
// Question / Answer implementations

int Quiz::findQuestionIndex(int questionID) const
{
	for (int i = 0; i < static_cast<int>(questions.size()); i++)
	{
		if (questions[i].getQuestionID() == questionID)
			return i;
	}
	return -1;
}
void Quiz::addQuestion(const Question& q)
{
	if (findQuestionIndex(q.getQuestionID()) != -1)
	{
		cout << "Question with this ID already exists in the quiz.\n";
		return;
	}
	questions.push_back(q);
}
void Quiz::addAnswerToQuestion(int questionID, const Answer& a)
{
	int idx = findQuestionIndex(questionID);
	if (idx == -1)
	{
		cout << "Question not found in this quiz.\n";
		return;
	}
	questions[idx].addAnswer(a);
}
void Quiz::markAnswerCorrect(int questionID, int answerID, bool isCorrect)
{
	int idx = findQuestionIndex(questionID);
	if (idx == -1)
	{
		cout << "Question not found in this quiz.\n";
		return;
	}
	questions[idx].markAnswerCorrect(answerID, isCorrect);
}

void Quiz::listQuestions() const
{
	if (questions.empty())
	{
		cout << "No questions in this quiz.\n";
		return;
	}
	for (const Question& q : questions)
		q.display();
}