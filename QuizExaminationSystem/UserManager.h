#pragma once
#include <vector>
#include <memory>
#include "User.h"

class UserManager {
private:
    std::vector<std::unique_ptr<User>> users;
    User* findUser(const std::string& username);

public:
    UserManager();

    bool registerAccount(const std::string& u, const std::string& p, Role r);
    User* login(const std::string& u, const std::string& p);
    bool resetPassword(const std::string& u, const std::string& newP);

    //Admin
    void viewUsers() const;
    bool deleteUser(const std::string& u);
};
