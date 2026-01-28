#include "ReviewSystem.h"
#include <iostream>

using namespace std;

void ReviewSystem::saveResult(const ExamResult& r) {
    results.push_back(r);
}

void ReviewSystem::reviewLastResult() const {
    if (results.empty()) {
        cout << "Chua co ket qua.\n";
        return;
    }

    const ExamResult& r = results.back();
    cout << "\n=== REVIEW QUIZ: " << r.quizTitle << " ===\n";
    cout << "Sinh vien: " << r.studentName << "\n";
    cout << "Diem: " << r.score << "\n";

    for (int i = 0; i < (int)r.logs.size(); i++) {
        const auto& log = r.logs[i];
        cout << "\nCau " << i + 1 << ": " << log.questionText << "\n";
        cout << "  Ban chon: " << log.chosenAnswer << "\n";
        cout << "  Dap an dung: " << log.correctAnswer << "\n";
        cout << "  Ket qua: " << (log.isCorrect ? "DUNG" : "SAI") << "\n";
    }
}

void ReviewSystem::viewAllResults() const {
    if (results.empty()) {
        cout << "Chua co du lieu.\n";
        return;
    }
    cout << "\n=== ALL EXAM RESULTS ===\n";
    for (const auto& r : results) {
        cout << "SV: " << r.studentName
            << " | Quiz: " << r.quizTitle
            << " | Diem: " << r.score << "\n";
    }
}
