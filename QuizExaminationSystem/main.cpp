#include <iostream>
#include "UserManager.h"
#include "Utils.h"
#include "QuizManager.h"
#include "ExamHandler.h"
#include "ReviewSystem.h"

using namespace std;

void adminMenu(UserManager& um);
void teacherMenu(QuizManager& qm);
void studentMenu(QuizManager& qm, ExamHandler& eh, ReviewSystem& rs);

int main() {
    UserManager um;
    QuizManager qm;
    ExamHandler eh;
    ReviewSystem rs;

    while (true) {
        cout << "\n=== ONLINE QUIZ SYSTEM ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Reset Password\n";
        cout << "0. Exit\n";

        int c = Utils::readInt("Chon: ", 0, 3);
        if (c == 0) break;

        if (c == 1) {
            string u = Utils::readString("Username: ");
            string p = Utils::readString("Password: ");
            int r = Utils::readInt("Role (1.Admin 2.Teacher 3.Student): ", 1, 3);
            if (um.registerAccount(u, p, (Role)r))
                cout << "Dang ky thanh cong!\n";
            else
                cout << "Username da ton tai!\n";
        }
        else if (c == 2) {
            string u = Utils::readString("Username: ");
            string p = Utils::readString("Password: ");

            User* user = um.login(u, p);
            if (!user) {
                cout << "Dang nhap that bai!\n";
                continue;
            }

            cout << "Xin chao " << user->getUsername()
                << " (" << user->getRoleName() << ")\n";

            if (user->getRole() == Role::Admin) adminMenu(um);
            else if (user->getRole() == Role::Teacher) teacherMenu(qm);
            else studentMenu(qm, eh, rs);
        }
        else if (c == 3) {
            string u = Utils::readString("Username: ");
            string p = Utils::readString("Password moi: ");
            if (um.resetPassword(u, p)) cout << "Reset thanh cong!\n";
            else cout << "Reset that bai!\n";
        }
    }
    return 0;
}

void adminMenu(UserManager& um) {
    while (true) {
        cout << "\n--- ADMIN MENU ---\n";
        cout << "1. View Users\n";
        cout << "2. Delete User\n";
        cout << "0. Logout\n";

        int c = Utils::readInt("Chon: ", 0, 2);
        if (c == 0) break;
        if (c == 1) um.viewUsers();
        else if (c == 2) {
            string u = Utils::readString("Username can xoa: ");
            if (um.deleteUser(u)) cout << "Xoa thanh cong!\n";
            else cout << "Khong xoa duoc!\n";
        }
    }
}

void teacherMenu(QuizManager& qm) {
    while (true) {
        cout << "\n--- TEACHER MENU ---\n";
        cout << "1. Create Quiz\n";
        cout << "2. Delete Quiz\n";
        cout << "3. List Quizzes\n";
        cout << "4. Add Question\n";
        cout << "5. Add Answer\n";
        cout << "6. Mark Correct Answer\n";
        cout << "7. Set Time Limit\n";
        cout << "8. Set Score / Question\n";
        cout << "9. Publish Quiz\n";
        cout << "0. Logout\n";

        int c = Utils::readInt("Chon: ", 0, 9);
        if (c == 0) break;

        switch (c) {
        case 1: qm.createQuiz(); break;
        case 2: qm.deleteQuiz(); break;
        case 3: qm.listAllQuizzes(); break;
        case 4: qm.addQuestion(); break;
        case 5: qm.addAnswer(); break;
        case 6: qm.markCorrectAnswer(); break;
        case 7: qm.setQuizTimeLimit(); break;
        case 8: qm.setScorePerQuestion(); break;
        case 9: qm.publishQuiz(); break;
        }
    }
}

void studentMenu(QuizManager& qm, ExamHandler& eh, ReviewSystem& rs) {
    while (true) {
        cout << "\n--- STUDENT MENU ---\n";
        cout << "1. View Available Quizzes\n";
        cout << "2. Take Quiz\n";
        cout << "3. Review Last Result\n";
        cout << "0. Logout\n";

        int c = Utils::readInt("Chon: ", 0, 3);
        if (c == 0) break;

        if (c == 1) {
            auto list = qm.getPublishedQuizzes();
            for (const auto& q : list)
                cout << q.getId() << " | " << q.getTitle() << "\n";
        }
        else if (c == 2) {
            auto list = qm.getPublishedQuizzes();
            if (list.empty()) {
                cout << "Chua co quiz nao.\n";
                continue;
            }
            for (const auto& q : list)
                cout << q.getId() << " | " << q.getTitle() << "\n";

            int id;
            cout << "Chon Quiz ID: ";
            cin >> id;

            Quiz* quiz = qm.getQuizById(id);
            if (!quiz || !quiz->isPublished()) {
                cout << "Quiz khong hop le.\n";
                continue;
            }
            string name = Utils::readString("Ten sinh vien: ");
            ExamResult r = eh.takeQuiz(*quiz, name);
            rs.saveResult(r);
        }
        else if (c == 3) {
            rs.reviewLastResult();
        }
    }
}
