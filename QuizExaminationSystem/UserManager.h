#pragma once
#include <vector>
#include "User.h"

/*
UserManager
Register Account
Login
Reset Password
Manage User (Admin)
*/
class UserManager {
private:
    std::vector<User> users;
    int findUserIndex(const std::string& username) const;

public:
    UserManager();

    bool registerAccount(const std::string& u, const std::string& p, Role r);
    User* login(const std::string& u, const std::string& p);
    bool resetPassword(const std::string& u, const std::string& newP);

    void viewUsers() const;
    bool deleteUser(const std::string& u);
    bool updateUserRole(const std::string& u, Role newRole);
};
