#include "ExamHandler.h"
#include <iostream>

using namespace std;
int ExamHandler::takeQuiz(const Quiz& quiz) {
    int score = 0;

    cout << "\nSTART QUIZ: " << quiz.getTitle() << "\n";

    for (const auto& q : quiz.getQuestions()) {
        cout << q.getContent() << "\n";

        const auto& answers = q.getAnswers();
        for (size_t i = 0; i < answers.size(); ++i) {
            cout << i + 1 << ". " << answers[i].getContent() << "\n";
        }

        int choice;
        cout << "Your answer: ";
        cin >> choice;

        if (choice >= 1 && choice <= answers.size()) {
            if (answers[choice - 1].getIsCorrect())
                score++;
        }
    }

    cout << "Quiz submitted.\n";
    return score;
}
