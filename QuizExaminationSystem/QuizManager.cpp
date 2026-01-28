#include "QuizManager.h"
#include <iostream>
using namespace std;

int QuizManager::findQuizIndex(int id) const {
    for (int i = 0; i < (int)quizzes.size(); i++)
        if (quizzes[i].getId() == id) return i;
    return -1;
}

void QuizManager::createQuiz() {
    int id;
    string title;
    cout << "Quiz ID: ";
    cin >> id;
    cin.ignore();
    cout << "Quiz title: ";
    getline(cin, title);

    if (findQuizIndex(id) != -1) {
        cout << "Quiz da ton tai!\n";
        return;
    }
    quizzes.push_back(Quiz(id, title));
    cout << "Tao quiz thanh cong.\n";
}

void QuizManager::deleteQuiz() {
    int id;
    cout << "Quiz ID can xoa: ";
    cin >> id;
    int idx = findQuizIndex(id);
    if (idx == -1) {
        cout << "Khong tim thay quiz.\n";
        return;
    }
    quizzes.erase(quizzes.begin() + idx);
    cout << "Da xoa quiz.\n";
}

void QuizManager::listAllQuizzes() const {
    cout << "\n--- DANH SACH QUIZ ---\n";
    for (const auto& q : quizzes) {
        cout << q.getId() << " | " << q.getTitle()
            << " | Published: " << (q.isPublished() ? "Yes" : "No") << "\n";
    }
}

void QuizManager::publishQuiz() {
    int id;
    cout << "Quiz ID can publish: ";
    cin >> id;
    int idx = findQuizIndex(id);
    if (idx == -1) {
        cout << "Khong tim thay quiz.\n";
        return;
    }
    if (quizzes[idx].getQuestions().empty()) {
        cout << "Quiz chua co cau hoi.\n";
        return;
    }
    quizzes[idx].publish();
    cout << "Publish thanh cong.\n";
}

void QuizManager::setQuizTimeLimit() {
    int id, t;
    cout << "Quiz ID: ";
    cin >> id;
    int idx = findQuizIndex(id);
    if (idx == -1) return;
    cout << "Time limit (minutes): ";
    cin >> t;
    quizzes[idx].setTimeLimit(t);
}

void QuizManager::setScorePerQuestion() {
    int id;
    double s;
    cout << "Quiz ID: ";
    cin >> id;
    int idx = findQuizIndex(id);
    if (idx == -1) return;
    cout << "Score per question: ";
    cin >> s;
    quizzes[idx].setScorePerQuestion(s);
}

void QuizManager::addQuestion() {
    int qz, qid;
    string text;
    cout << "Quiz ID: ";
    cin >> qz;
    int idx = findQuizIndex(qz);
    if (idx == -1) return;

    cout << "Question ID: ";
    cin >> qid;
    cin.ignore();
    cout << "Question text: ";
    getline(cin, text);

    quizzes[idx].addQuestion(Question(qid, text));
}

void QuizManager::addAnswer() {
    int qz, qid, aid;
    string text;
    cout << "Quiz ID: ";
    cin >> qz;
    int idx = findQuizIndex(qz);
    if (idx == -1) return;

    cout << "Question ID: ";
    cin >> qid;
    cout << "Answer ID: ";
    cin >> aid;
    cin.ignore();
    cout << "Answer text: ";
    getline(cin, text);

    quizzes[idx].addAnswerToQuestion(qid, Answer(aid, text, false));
}

void QuizManager::markCorrectAnswer() {
    int qz, qid, aid;
    cout << "Quiz ID: ";
    cin >> qz;
    int idx = findQuizIndex(qz);
    if (idx == -1) return;

    cout << "Question ID: ";
    cin >> qid;
    cout << "Correct Answer ID: ";
    cin >> aid;

    quizzes[idx].markCorrectAnswer(qid, aid);
}

vector<Quiz> QuizManager::getPublishedQuizzes() const {
    vector<Quiz> res;
    for (const auto& q : quizzes)
        if (q.isPublished()) res.push_back(q);
    return res;
}

Quiz* QuizManager::getQuizById(int id) {
    int idx = findQuizIndex(id);
    if (idx == -1) return nullptr;
    return &quizzes[idx];
}
