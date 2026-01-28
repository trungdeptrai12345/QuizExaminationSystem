#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "QuizManager.h"

class Result {
public:
    int resultID;
    int userID;
    int quizID;
    double score;
    std::string completedAt;

    Result(int rID, int uID, int qID, double s) 
        : resultID(rID), userID(uID), quizID(qID), score(s) {
        time_t now = time(0);
        completedAt = ctime(&now); 
    }

    void displayResult() {
        std::cout << "\n--- KET QUA THI ---" << std::endl;
        std::cout << "Quiz ID: " << quizID << " | Diem so: " << score << std::endl;
        std::cout << "Thoi gian hoan thanh: " << completedAt;
    }
};

class ExamHandler {
public:
    void startExam(QuizManager& manager, int uID) {
        int qID;
        std::cout << "Nhap ID de thi muon lam: ";
        std::cin >> qID;

        int index = manager.findQuizIndex(qID);
        if (index == -1) {
            std::cout << "Loi: Khong tim thay de thi nay!\n";
            return;
        }

        std::cout << "\n--- BAT DAU LAM BAI (Auto Grading Mode) ---" << std::endl;
        int correctCount = 0;
        int totalQ = 5; 

        for(int i = 1; i <= totalQ; i++) {
            char ans;
            std::cout << "Cau " << i << " (Chon A/B/C/D): ";
            std::cin >> ans;
            if (toupper(ans) == 'A') correctCount++;
        }

        double finalScore = (double)correctCount * 2.0; 
        
        Result res(1, uID, qID, finalScore);
        res.displayResult();
    }
};
