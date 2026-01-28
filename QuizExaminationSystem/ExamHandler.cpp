void menuNgocHuy(QuizManager& qm) {
    ExamHandler eh;
    int choice;
    do {
        std::cout << "\n--- MENU THI & KIEM THU (NGUYEN NGOC HUY) ---";
        std::cout << "\n1. Vao thi (Take Quiz)";
        std::cout << "\n2. Cham diem tu dong (Auto Grading)";
        std::cout << "\n3. Nop bai & Luu ket qua (Submit Quiz)";
        std::cout << "\n0. Thoat";
        std::cout << "\nChon chuc nang: ";
        std::cin >> choice;

        if (choice == 1) eh.startExam(qm, 101);
    } while (choice != 0);
}
