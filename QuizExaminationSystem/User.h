#pragma once
#include <string>

enum class Role {
    Admin = 1,
    Teacher = 2,
    Student = 3
};

class User {
protected:
    std::string username;
    std::string passwordHash;
    Role role;

public:
    User(std::string u, std::string pHash, Role r);
    virtual ~User() = default;

    std::string getUsername() const;
    Role getRole() const;
    std::string getRoleName() const;

    bool checkPassword(const std::string& plain) const;
    void setPassword(const std::string& newPlain);
};
