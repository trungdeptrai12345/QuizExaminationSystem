#pragma once
#pragma once
#include <vector>
#include <memory>
#include "User.h"

class UserManager {
private:
    std::vector<std::unique_ptr<User>> users;

    User* findUserInternal(const std::string& username);

public:
    UserManager();

    bool registerAccount(const std::string& username, const std::string& password, Role role);
    User* login(const std::string& username, const std::string& password);
    bool resetPassword(const std::string& username, const std::string& newPassword);

    void listUsers() const;
    bool deleteUser(const std::string& username);

    bool usernameExists(const std::string& username);
};
