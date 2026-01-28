#include <iostream>
#include "QuizManager.h"
#include "ExamHandler.h"

using namespace std;
int main() {
    QuizManager quizManager;
    ExamHandler examHandler;

    Quiz quiz1(1, "OOP Basics", 10);

    Question q1("What is OOP?");
    q1.addAnswer(Answer("Object Oriented Programming", true));
    q1.addAnswer(Answer("Only One Program", false));

    quiz1.addQuestion(q1);
    quiz1.publish();
    quizManager.createQuiz(quiz1);

    auto quizzes = quizManager.getPublishedQuizzes();
    if (quizzes.empty()) {
        cout << "No quiz available.\n";
        return 0;
    }

    cout << "\nAvailable quizzes:\n";
    for (auto& q : quizzes)
        cout << q.getID() << ". " << q.getTitle() << "\n";

    int id;
    cout << "Choose quiz ID: ";
    cin >> id;

    Quiz* chosen = quizManager.findQuizByID(id);
    if (!chosen) {
        cout << "Invalid quiz.\n";
        return 0;
    }

    int score = examHandler.takeQuiz(*chosen);
    cout << "\nYour score: " << score << "/" << chosen->getQuestions().size() << "\n";

    return 0;
}
