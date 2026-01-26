#pragma once
#include <string>

enum class Role {
    Admin = 1,
    Teacher = 2,
    Student = 3
};

// ===== Entity: User =====
class User {
protected:
    std::string username;
    std::string passwordHash;
    Role role;

public:
    User(std::string u, std::string p, Role r);
    virtual ~User() = default;

    std::string getUsername() const;
    Role getRole() const;
    bool checkPassword(const std::string& plain) const;
    void setPassword(const std::string& newPlain);

    virtual std::string getRoleName() const;
};

class Admin : public User {
public:
    Admin(std::string u, std::string p);
};

class Teacher : public User {
public:
    Teacher(std::string u, std::string p);
};

class Student : public User {
public:
    Student(std::string u, std::string p);
};
