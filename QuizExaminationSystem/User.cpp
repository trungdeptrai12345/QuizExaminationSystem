#include "User.h"
#include "Utils.h"

User::User(std::string u, std::string p, Role r)
    : username(u), passwordHash(p), role(r) {
}

std::string User::getUsername() const { return username; }
Role User::getRole() const { return role; }

bool User::checkPassword(const std::string& plain) const {
    return passwordHash == Utils::hashPassword(plain);
}

void User::setPassword(const std::string& newPlain) {
    passwordHash = Utils::hashPassword(newPlain);
}

std::string User::getRoleName() const {
    if (role == Role::Admin) return "Admin";
    if (role == Role::Teacher) return "Teacher";
    return "Student";
}

Admin::Admin(std::string u, std::string p)
    : User(u, p, Role::Admin) {
}

Teacher::Teacher(std::string u, std::string p)
    : User(u, p, Role::Teacher) {
}

Student::Student(std::string u, std::string p)
    : User(u, p, Role::Student) {
}
