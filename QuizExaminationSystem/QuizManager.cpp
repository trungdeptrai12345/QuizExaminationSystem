#include "QuizManager.h"
#include <iostream>
using namespace std;

int QuizManager::findQuizIndex(int quizID)
{
	//Used to: Saerch for a quiz in the quiz list by quizID, return the index of quiz if found and -1 if does not exist
	for (int i = 0; i < quizzes.size(); i++) // Loop through all quizzes in the vector
	{
		if (quizzes[i].getQuizID() == quizID) //Check if current quiz has the same ID
		return i; // Quiz found
	}
	return -1; // Quiz not found
}
void QuizManager::createQuiz() // Actor: Teacher/Admin
{
	int id;
	string title, decs;
	cout << "Enter Quiz ID: "; // User input quiz ID
	cin >> id;
	if (findQuizIndex(id) != -1) //Check if quiz with same ID already exists
	{
		cout << "Quiz with this ID already exists!!! \n";
		return;
	}
	cin.ignore(); //Clear buffer to avoid input error
	cout << "Enter Title: "; //User input quiz title
	getline(cin, title);
	cout << "Enter description: "; //User input quiz description
	getline(cin, decs);
	quizzes.push_back(Quiz(id, title, decs)); //Create new quiz and add to the vector
	cout << "Quiz created successfully!!!\n";
}
void QuizManager::updateQuiz() // Actor: Teacher/Admin
{
	int id;
	cout << "Enter quiz ID: ";// User input quiz ID
	cin >> id;
	cin.ignore();
	int index = findQuizIndex(id);//Find quiz position in vector
	if (index == -1) //If quiz does not exist
	{
		cout << "Quiz not found!!! \n";
		return;
	}
	string title, decs;
	cout << "New title: ";//Input new title
	getline(cin, title);
	cout << "New description: ";//Input new description
	getline(cin, decs);
	quizzes[index].updateQuiz(title, decs); //Update quiz information
	cout << "Quiz update successfully!!!\n";
}
void QuizManager::deleteQuiz() // Actor: Teacher/Admin
{
	int id;
	cout << "Enter Quiz ID: ";// User input quiz ID
	cin >> id;
	int index = findQuizIndex(id); //Find quiz position in vector
	if (index == -1) //If quiz does not exist
	{
		cout << "Quiz not found!!! \n";
		return;
	}
	quizzes.erase(quizzes.begin() + index);// Remove quiz from vector
	cout << "Quiz deleted successfully!!!\n";
}
void QuizManager::publishQuiz() // Actor: Teacher/Admin
{
	int id;
	cout << "Enter Quiz ID: ";// User input quiz ID
	cin >> id;
	int index = findQuizIndex(id); //Find quiz position in vector
	if (index == -1) //If quiz does not exist
	{
		cout << "Quiz not found!!! \n";
		return;
	}
	quizzes[index].publishQuiz(); //Publish the quiz
	cout << "Quiz published successfully!!!\n";
}

void QuizManager::setQuizTimeLimit() // Actor: Teacher/Admin
{
	int id, time;
	cout << "Enter Quiz ID: ";// User input quiz ID
	cin >> id;
	int index = findQuizIndex(id); //Find quiz position in vector
	if (index == -1) //If quiz does not exist
	{
		cout << "Quiz not found!!! \n";
		return;
	}
	cout << "Enter time limit (minutes): ";// User input time limit
	cin >> time;
	if (time <= 0) //Check for valid time limit
	{
		cout << "Invalid time limit!!! \n";
		return;
	}
	else
	{
		quizzes[index].setTimeLimit(time);
		cout << "Time limit set successfully!!!\n";
	}
}
void QuizManager::setScoringRules() // Actor: Teacher/Admin
{
	int id;
	double score;
	cout << "Enter Quiz ID: ";// User input quiz ID
	cin >> id;
	int index = findQuizIndex(id); //Find quiz position in vector
	if (index == -1) //If quiz does not exist
	{
		cout << "Quiz not found!!! \n";
		return;
	}
	cout << "Enter score per question: ";//User input score per question
	cin >> score;
	if (score < 0) //Check for valid score
	{
		cout << "Score cannot be negative!!! \n";
		return;
	}
	else
	{
		quizzes[index].setScoringRules(score);
		cout << "Scoring rules set successfully!!!\n";
	}
}

void QuizManager::listQuizzes()
{
	if (quizzes.empty()) //Check if quiz list is empty
	{
		cout<<"No quizzes available.\n";
		return;
	}
	for (const Quiz& q : quizzes) //Loop through all quizzes and display
	{
		q.display();
	}
}