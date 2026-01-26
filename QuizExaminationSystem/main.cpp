#include <iostream>
#include "UserManager.h"
#include "Utils.h"

static void adminMenu(UserManager& um);
static void teacherMenu();
static void studentMenu();

static void showRoleMenu() {
    std::cout << "Chon role:\n";
    std::cout << "1. Admin\n";
    std::cout << "2. Teacher\n";
    std::cout << "3. Student\n";
}

int main() {
    UserManager userManager;

    while (true) {
        std::cout << "\nQUIZ EXAMINATION SYSTEM (Console Demo)\n";
        std::cout << "1. Register Account\n";
        std::cout << "2. Login\n";
        std::cout << "3. Reset Password\n";
        std::cout << "0. Exit\n";

        int choice = Utils::readInt("Chon: ", 0, 3);

        if (choice == 0) {
            std::cout << "Thoat chuong trinh.\n";
            break;
        }

        if (choice == 1) {
            std::string username = Utils::readNonEmpty("Nhap username: ");
            std::string password = Utils::readNonEmpty("Nhap password: ");

            showRoleMenu();
            int r = Utils::readInt("Role (1-3): ", 1, 3);
            Role role = static_cast<Role>(r);

            bool ok = userManager.registerAccount(username, password, role);
            if (ok) std::cout << "Dang ky thanh cong!\n";
            else std::cout << "Dang ky that bai (co the username da ton tai).\n";
        }
        else if (choice == 2) {
            std::string username = Utils::readNonEmpty("Nhap username: ");
            std::string password = Utils::readNonEmpty("Nhap password: ");

            User* user = userManager.login(username, password);
            if (!user) {
                std::cout << "Dang nhap that bai (sai user/pass).\n";
                continue;
            }

            std::cout << "Dang nhap thanh cong! Xin chao " << user->getUsername()
                << " (" << user->roleName() << ")\n";

            if (user->getRole() == Role::Admin) {
                adminMenu(userManager);
            }
            else if (user->getRole() == Role::Teacher) {
                teacherMenu();
            }
            else {
                studentMenu();
            }
        }
        else if (choice == 3) {
            std::string username = Utils::readNonEmpty("Nhap username can reset: ");
            std::string newPass = Utils::readNonEmpty("Nhap password moi: ");

            bool ok = userManager.resetPassword(username, newPass);
            if (ok) std::cout << "Reset password thanh cong!\n";
            else std::cout << "Reset that bai (khong tim thay user).\n";
        }
    }
    return 0;
}

static void adminMenu(UserManager& um) {
    while (true) {
        std::cout << "\n--- ADMIN MENU ---\n";
        std::cout << "1. List Users\n";
        std::cout << "2. Delete User\n";
        std::cout << "0. Logout\n";

        int c = Utils::readInt("Chon: ", 0, 2);
        if (c == 0) break;

        if (c == 1) {
            um.listUsers();
        }
        else if (c == 2) {
            std::string uname = Utils::readNonEmpty("Nhap username can xoa: ");
            bool ok = um.deleteUser(uname);
            if (ok) std::cout << "Xoa user thanh cong.\n";
            else std::cout << "Xoa that bai (khong tim thay / khong duoc xoa admin).\n";
        }
    }
}

static void teacherMenu() {
    while (true) {
        std::cout << "\n--- TEACHER MENU ---\n";
        std::cout << "(Cho phep nhom vien #2 ghep: Manage Quiz, Configure Quiz Settings)\n";
        std::cout << "0. Logout\n";
        int c = Utils::readInt("Chon: ", 0, 0);
        if (c == 0) break;
    }
}

static void studentMenu() {
    while (true) {
        std::cout << "\n--- STUDENT MENU ---\n";
        std::cout << "(Cho phep nhom vien #4/#5 ghep: View Quizzes, Take Quiz, Submit, View Result, Review)\n";
        std::cout << "0. Logout\n";
        int c = Utils::readInt("Chon: ", 0, 0);
        if (c == 0) break;
    }
}
