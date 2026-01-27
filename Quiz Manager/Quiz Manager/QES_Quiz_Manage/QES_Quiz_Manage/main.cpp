#include "QuizManager.h"
#include <iostream>
using namespace std;

//Used by Teacher/Admin

int main()
{
	QuizManager manager; //Create an object of QuizManager class
	int choice;// To store user choice
	do //display menu until user chooses to exit
	{
		cout << "   QUIZ MANAGEMENT MENU   \n";
		cout << "1. Create quiz.\n";
		cout << "2. Update quiz.\n";
		cout << "3. Delete quiz.\n";
		cout << "4. Publish quiz.\n";
		cout << "5. Set time limit.\n";
		cout << "6. Set scoring rules.\n";
		cout << "7. View quiz list.\n";
		cout << "8. Manage question & answers.\n";
		cout << "0. Exit.\n";
		cout << "Choose: ";// Ask user for choice
		cin >> choice;
		switch (choice)
		{
		case 1: manager.createQuiz(); //Call createQuiz method
			break;
		case 2: manager.updateQuiz(); //Call updateQuiz method
			break;
		case 3: manager.deleteQuiz(); //Call deleteQuiz method
			break;
		case 4: manager.publishQuiz();//Call publishQuiz method
			break;
		case 5: manager.setQuizTimeLimit(); //Call setQuizTimeLimit method
			break;
		case 6: manager.setScoringRules(); //Call setScoringRules method
			break;
		case 7: manager.listQuizzes(); //Call listQuizzes method
			break;
		case 8:
		{
			int sub;
			do
			{
				cout << " Question Management Menu\n";
				cout << " 1. Add question to quiz\n";
				cout << " 2. Add answer to question\n";
				cout << " 3. Mark/unmark answer as correct\n";
				cout << " 4. List questions in quiz\n";
				cout << " 0. Back\n";
				cout << " Choose: ";
				cin >> sub;
				switch (sub)
				{
				case 1: manager.createQuestion(); break;
				case 2: manager.addAnswerToQuestion(); break;
				case 3: manager.markAnswerCorrect(); break;
				case 4: manager.listQuestionsInQuiz(); break;
				case 0: break;
				default: cout << "Invalid choice. Try again.\n";
				}
			} while (sub != 0);
		}
		break;
		case 0: cout << "Exit the system\n"; //Exit 
			break;
		default: cout << "Invalid choice. Please try again!!!\n";
		}
	}
	while (choice != 0);// Continue until user chooses to exit
	return 0;
}