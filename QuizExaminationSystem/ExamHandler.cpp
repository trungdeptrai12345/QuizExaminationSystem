#include "ExamHandler.h"
#include <iostream>

using namespace std;

ExamResult ExamHandler::takeQuiz(const Quiz& quiz, const string& studentName) {
    ExamResult res;
    res.studentName = studentName;
    res.quizId = quiz.getId();
    res.quizTitle = quiz.getTitle();
    res.totalQuestions = (int)quiz.getQuestions().size();
    res.correctCount = 0;

    cout << "\n=== TAKE QUIZ: " << quiz.getTitle() << " ===\n";
    cout << "Time limit (minutes): " << quiz.getTimeLimit() << "\n";
    cout << "Score / question: " << quiz.getScorePerQuestion() << "\n";

    for (const auto& q : quiz.getQuestions()) {
        QuestionLog log;
        log.questionText = q.getText();
        log.isCorrect = false;
        log.correctAnswer = "(none)";

        cout << "\n" << q.getText() << "\n";
        int idx = 1;
        for (const auto& a : q.getAnswers()) {
            cout << idx++ << ". " << a.getText() << "\n";
            if (a.isCorrect()) log.correctAnswer = a.getText();
        }

        int choice;
        cout << "Chon dap an: ";
        cin >> choice;

        if (choice >= 1 && choice <= (int)q.getAnswers().size()) {
            const auto& chosen = q.getAnswers()[choice - 1];
            log.chosenAnswer = chosen.getText();
            log.isCorrect = chosen.isCorrect();
            if (log.isCorrect) res.correctCount++;
        }
        else {
            log.chosenAnswer = "Khong chon";
        }

        res.logs.push_back(log);
    }

    res.score = res.correctCount * quiz.getScorePerQuestion();

    cout << "\n--- SUBMIT QUIZ ---\n";
    cout << "Dung: " << res.correctCount << "/" << res.totalQuestions << "\n";
    cout << "Diem: " << res.score << "\n";

    return res;
}
