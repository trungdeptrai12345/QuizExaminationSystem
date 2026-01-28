#include "ReviewSystem.h"
#include <iostream>

using namespace std;

void ReviewSystem::startExam(const Quiz& quiz, string studentName) {
    ExamResult res;
    res.studentName = studentName;
    res.quizTitle = quiz.getTitle();
    res.score = 0;

    const auto& questions = quiz.getQuestions();
    res.total = questions.size();

    cout << "\n--- BAT DAU BAI THI: " << quiz.getTitle() << " ---\n";

    for (const auto& q : questions) {
        cout << "\n" << q.getContent() << "\n";

        const auto& answers = q.getAnswers();
        for (size_t i = 0; i < answers.size(); ++i) {
            cout << i + 1 << ". " << answers[i].getContent() << "\n";
        }

        int choice;
        cout << "Chon dap an: ";
        cin >> choice;

        QuestionLog log;
        log.questionText = q.getContent();

        for (const auto& ans : answers) {
            if (ans.getIsCorrect()) log.correctAnswer = ans.getContent();
        }

        if (choice >= 1 && choice <= answers.size()) {
            log.userChoice = answers[choice - 1].getContent();
            if (answers[choice - 1].getIsCorrect()) {
                res.score++;
                log.isCorrect = true;
            }
            else {
                log.isCorrect = false;
            }
        }
        else {
            log.userChoice = "Khong chon hoac sai cu phap";
            log.isCorrect = false;
        }
        res.history.push_back(log);
    }

    cout << "\nDa nop bai! Diem: " << res.score << "/" << res.total << "\n";
    database.push_back(res);
}

void ReviewSystem::reviewLastExam() {
    if (database.empty()) {
        cout << "Chua co du lieu.\n";
        return;
    }
    ExamResult last = database.back();
    cout << "\n--- REVIEW BAI THI: " << last.quizTitle << " ---\n";
    for (int i = 0; i < last.history.size(); i++) {
        QuestionLog q = last.history[i];
        cout << "Cau " << i + 1 << ": " << q.questionText << "\n";
        cout << " -> Chon: " << q.userChoice << "\n";
        cout << " -> Ket qua: " << (q.isCorrect ? "DUNG" : "SAI") << "\n";
        if (!q.isCorrect) cout << " -> Dap an dung: " << q.correctAnswer << "\n";
    }
}

void ReviewSystem::showStatistics() {
    cout << "\n--- THONG KE KET QUA ---\n";
    if (database.empty()) return;
    for (auto& r : database) r.printLine();
}