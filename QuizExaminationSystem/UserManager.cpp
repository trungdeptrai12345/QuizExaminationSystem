#include "UserManager.h"
#include "Utils.h"
#include <iostream>
#include <algorithm>

UserManager::UserManager() {
    registerAccount("admin", "admin123", Role::Admin);
}

User* UserManager::findUser(const std::string& username) {
    for (auto& u : users)
        if (u->getUsername() == username)
            return u.get();
    return nullptr;
}

bool UserManager::registerAccount(const std::string& u, const std::string& p, Role r) {
    if (findUser(u)) return false;

    std::string hash = Utils::hashPassword(p);

    if (r == Role::Admin)
        users.push_back(std::make_unique<Admin>(u, hash));
    else if (r == Role::Teacher)
        users.push_back(std::make_unique<Teacher>(u, hash));
    else
        users.push_back(std::make_unique<Student>(u, hash));

    return true;
}

User* UserManager::login(const std::string& u, const std::string& p) {
    User* user = findUser(u);
    if (!user) return nullptr;
    if (!user->checkPassword(p)) return nullptr;
    return user;
}

bool UserManager::resetPassword(const std::string& u, const std::string& newP) {
    User* user = findUser(u);
    if (!user) return false;
    user->setPassword(newP);
    return true;
}

void UserManager::viewUsers() const {
    std::cout << "\n--- USER LIST ---\n";
    for (const auto& u : users)
        std::cout << u->getUsername() << " | " << u->getRoleName() << "\n";
}

bool UserManager::deleteUser(const std::string& u) {
    if (u == "admin") return false;
    auto it = std::remove_if(users.begin(), users.end(),
        [&](const std::unique_ptr<User>& x) { return x->getUsername() == u; });
    if (it == users.end()) return false;
    users.erase(it, users.end());
    return true;
}
