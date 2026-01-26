#pragma once
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
    User() = default;
    User(std::string uname, std::string pwHash, Role r);
    virtual ~User() = default;

    std::string getUsername() const;
    Role getRole() const;

    bool verifyPassword(const std::string& plainPassword) const;
    void setPassword(const std::string& newPlainPassword);

    virtual std::string roleName() const;
};

class Admin : public User {
public:
    Admin(std::string uname, std::string pwHash);
    std::string roleName() const override;
};

class Teacher : public User {
public:
    Teacher(std::string uname, std::string pwHash);
    std::string roleName() const override;
};

class Student : public User {
public:
    Student(std::string uname, std::string pwHash);
    std::string roleName() const override;
};
