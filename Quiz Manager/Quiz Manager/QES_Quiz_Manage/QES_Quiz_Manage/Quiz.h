#pragma once
#include <String>
#include <vector>
#include "Question.h"
using namespace std;
/*
Class: Quiz
Used to: 
 - Represent a quiz object in the system.
 - Store all basic information related to a quiz.
 - Provide methods to update and configure quiz settings
*/

class Quiz
{
private:
	int quizID; // Unique ID of quiz
	string title; // Quiz title
	string description; // Quiz description
	int timeLimit; // Time limit (minutes)
	bool isPublished; // Quiz status (published / unpublished)
	double scorePerQuestion; //Score for each correct question
	// Questions storage
	vector<Question> questions;
	int findQuestionIndex(int questionID) const;

public:
	Quiz(int id, string t, string d); // Initialize a new quiz with default values
	void updateQuiz(string t, string d); // Upadate basic quiz information
	void publishQuiz(); // Publish the quiz
	void setTimeLimit(int minutes); //Set time limit for the quiz
	void setScoringRules(double score); //Set scoring rules for the quiz
	void display() const; // Display quiz information
	int getQuizID() const;
	bool getStatus() const;
	// Question / Answer APIs
	void addQuestion(const Question& q);
	void addAnswerToQuestion(int questionID, const Answer& a);
	void markAnswerCorrect(int questionID, int answerID, bool isCorrect);
	void listQuestions() const;
};