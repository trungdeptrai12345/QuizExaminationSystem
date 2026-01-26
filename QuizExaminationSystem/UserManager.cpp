#include "UserManager.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>

UserManager::UserManager() {
    // Tạo sẵn tài khoản admin để demo hệ thống (thực tế có thể load file)
    registerAccount("admin", "admin123", Role::Admin);
}

User* UserManager::findUserInternal(const std::string& username) {
    for (auto& u : users) {
        if (u->getUsername() == username) return u.get();
    }
    return nullptr;
}

bool UserManager::usernameExists(const std::string& username) {
    return findUserInternal(username) != nullptr;
}

// Use Case: Register Account (Guest)
bool UserManager::registerAccount(const std::string& username, const std::string& password, Role role) {
    if (username.empty() || password.empty()) return false;
    if (usernameExists(username)) return false;

    std::string pwHash = Utils::hashPassword(password);

    if (role == Role::Admin) {
        users.push_back(std::make_unique<Admin>(username, pwHash));
    }
    else if (role == Role::Teacher) {
        users.push_back(std::make_unique<Teacher>(username, pwHash));
    }
    else {
        users.push_back(std::make_unique<Student>(username, pwHash));
    }
    return true;
}

User* UserManager::login(const std::string& username, const std::string& password) {
    User* u = findUserInternal(username);
    if (!u) return nullptr;
    if (!u->verifyPassword(password)) return nullptr;
    return u;
}

bool UserManager::resetPassword(const std::string& username, const std::string& newPassword) {
    User* u = findUserInternal(username);
    if (!u) return false;
    u->setPassword(newPassword);
    return true;
}

void UserManager::listUsers() const {
    std::cout << "\n=== DANH SACH USER ===\n";
    if (users.empty()) {
        std::cout << "(rong)\n";
        return;
    }
    for (const auto& u : users) {
        std::cout << "- " << u->getUsername() << " | Role: " << u->roleName() << "\n";
    }
}

bool UserManager::deleteUser(const std::string& username) {
    if (username == "admin") return false;

    auto it = std::remove_if(users.begin(), users.end(),
        [&](const std::unique_ptr<User>& u) { return u->getUsername() == username; });

    if (it == users.end()) return false;
    users.erase(it, users.end());
    return true;
}

bool UserManager::adminAddUser(const std::string& username, const std::string& password, Role role) {
    return registerAccount(username, password, role);
}

bool UserManager::adminUpdateUserRole(const std::string& username, Role newRole) {
    User* u = findUserInternal(username);
    if (!u) return false;
    if (username == "admin") return false;

    return false;
}

bool UserManager::adminUpdateUserPassword(const std::string& username, const std::string& newPassword) {
    return resetPassword(username, newPassword);
}

