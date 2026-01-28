#include "UserManager.h"
#include "Utils.h"
#include <iostream>

using namespace std;

UserManager::UserManager() {
    users.push_back(User("admin", Utils::hashPassword("admin123"), Role::Admin));
}

int UserManager::findUserIndex(const string& username) const {
    for (int i = 0; i < (int)users.size(); i++) {
        if (users[i].getUsername() == username)
            return i;
    }
    return -1;
}

bool UserManager::registerAccount(const string& u, const string& p, Role r) {
    if (findUserIndex(u) != -1) return false;
    users.push_back(User(u, Utils::hashPassword(p), r));
    return true;
}

User* UserManager::login(const string& u, const string& p) {
    int idx = findUserIndex(u);
    if (idx == -1) return nullptr;
    if (!users[idx].checkPassword(p)) return nullptr;
    return &users[idx];
}

bool UserManager::resetPassword(const string& u, const string& newP) {
    int idx = findUserIndex(u);
    if (idx == -1) return false;
    users[idx].setPassword(newP);
    return true;
}

void UserManager::viewUsers() const {
    cout << "\n--- USER LIST ---\n";
    for (const auto& u : users) {
        cout << u.getUsername() << " | " << u.getRoleName() << "\n";
    }
}

// Admin: Delete User
bool UserManager::deleteUser(const string& u) {
    if (u == "admin") return false;
    int idx = findUserIndex(u);
    if (idx == -1) return false;
    users.erase(users.begin() + idx);
    return true;
}

bool UserManager::updateUserRole(const string& u, Role newRole) {
    int idx = findUserIndex(u);
    if (idx == -1) return false;
    users[idx] = User(u, users[idx].checkPassword("") ? "" : "", newRole);
    return true;
}
