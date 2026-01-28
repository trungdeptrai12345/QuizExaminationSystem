#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct QuestionLog {
    string questionText;
    string userChoice;
    string correctAnswer;
    bool isCorrect;
};

struct ExamResult {
    string studentName;
    string quizTitle;
    int score;
    int total;
    vector<QuestionLog> history;

    void printLine() {
        cout << "SV: " << studentName << " | De: " << quizTitle
            << " | Diem: " << score << "/" << total << endl;
    }
};