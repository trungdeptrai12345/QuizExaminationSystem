#include <iostream>
#include "QuizManager.h" 
#include "ExamHandler.h" 

using namespace std;

int main() {
    QuizManager qm; 
    ExamHandler eh; 
    int mainChoice;

    do {
        cout << "\n--- HE THONG QUAN LY THI (QUICK QUIZ) ---\n";
        cout << "1. Quan ly de thi (Admin - Vinh Chi)\n";
        cout << "2. Lam bai thi & Cham diem (Student - Ngoc Huy)\n";
        cout << "0. Thoat\n";
        cout << "Chon vai tro: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            
        } 
        else if (mainChoice == 2) {
            
            eh.menuNgocHuy(qm); 
        }
    } while (mainChoice != 0);

    return 0;
}
