#include "User.h"
#include "Utils.h"

User::User(std::string uname, std::string pwHash, Role r)
    : username(std::move(uname)), passwordHash(std::move(pwHash)), role(r) {
}

std::string User::getUsername() const { return username; }
Role User::getRole() const { return role; }

bool User::verifyPassword(const std::string& plainPassword) const {
    return passwordHash == Utils::hashPassword(plainPassword);
}

void User::setPassword(const std::string& newPlainPassword) {
    passwordHash = Utils::hashPassword(newPlainPassword);
}

std::string User::roleName() const {
    switch (role) {
    case Role::Admin: return "Admin";
    case Role::Teacher: return "Teacher";
    case Role::Student: return "Student";
    default: return "Unknown";
    }
}

Admin::Admin(std::string uname, std::string pwHash)
    : User(std::move(uname), std::move(pwHash), Role::Admin) {
}

std::string Admin::roleName() const { return "Admin"; }

Teacher::Teacher(std::string uname, std::string pwHash)
    : User(std::move(uname), std::move(pwHash), Role::Teacher) {
}

std::string Teacher::roleName() const { return "Teacher"; }

Student::Student(std::string uname, std::string pwHash)
    : User(std::move(uname), std::move(pwHash), Role::Student) {
}

std::string Student::roleName() const { return "Student"; }
