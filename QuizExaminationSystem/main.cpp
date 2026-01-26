#include <iostream>
#include "UserManager.h"
#include "Utils.h"

void adminMenu(UserManager& um);

int main() {
    UserManager um;

    while (true) {
        std::cout << "\n=== ONLINE QUIZ SYSTEM ===\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Reset Password\n";
        std::cout << "0. Exit\n";

        int c = Utils::readInt("Chon: ", 0, 3);

        if (c == 0) break;

        if (c == 1) {
            std::string u = Utils::readString("Username: ");
            std::string p = Utils::readString("Password: ");
            int r = Utils::readInt("Role (1.Admin 2.Teacher 3.Student): ", 1, 3);

            if (um.registerAccount(u, p, (Role)r))
                std::cout << "Dang ky thanh cong!\n";
            else
                std::cout << "Dang ky that bai!\n";
        }

        if (c == 2) {
            std::string u = Utils::readString("Username: ");
            std::string p = Utils::readString("Password: ");

            User* user = um.login(u, p);
            if (!user) {
                std::cout << "Dang nhap that bai!\n";
                continue;
            }

            std::cout << "Xin chao " << user->getRoleName() << "\n";

            if (user->getRole() == Role::Admin)
                adminMenu(um);
            else
                std::cout << "(Menu nay thuoc phan nguoi khac)\n";
        }

        if (c == 3) {
            std::string u = Utils::readString("Username: ");
            std::string p = Utils::readString("Password moi: ");
            if (um.resetPassword(u, p))
                std::cout << "Reset thanh cong!\n";
            else
                std::cout << "Reset that bai!\n";
        }
    }
}

void adminMenu(UserManager& um) {
    while (true) {
        std::cout << "\n--- ADMIN MENU ---\n";
        std::cout << "1. View Users\n";
        std::cout << "2. Delete User\n";
        std::cout << "0. Logout\n";

        int c = Utils::readInt("Chon: ", 0, 2);
        if (c == 0) break;

        if (c == 1) um.viewUsers();
        if (c == 2) {
            std::string u = Utils::readString("Username can xoa: ");
            if (um.deleteUser(u))
                std::cout << "Xoa thanh cong!\n";
            else
                std::cout << "Khong xoa duoc!\n";
        }
    }
}
