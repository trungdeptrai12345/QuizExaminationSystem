#pragma once
#include <string>
#include <vector>

using namespace std;

struct QuestionLog {
    string questionText;
    string chosenAnswer;
    string correctAnswer;
    bool isCorrect;
};

struct ExamResult {
    string studentName;
    int quizId;
    string quizTitle;
    int totalQuestions;
    int correctCount;
    double score;
    vector<QuestionLog> logs;
};
