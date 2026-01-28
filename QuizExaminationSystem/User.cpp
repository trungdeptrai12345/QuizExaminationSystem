#include "User.h"
#include "Utils.h"

using namespace std;

User::User(string u, string pHash, Role r)
    : username(u), passwordHash(pHash), role(r) {
}

string User::getUsername() const { return username; }
Role User::getRole() const { return role; }

string User::getRoleName() const {
    if (role == Role::Admin) return "Admin";
    if (role == Role::Teacher) return "Teacher";
    return "Student";
}

bool User::checkPassword(const string& plain) const {
    return passwordHash == Utils::hashPassword(plain);
}

void User::setPassword(const string& newPlain) {
    passwordHash = Utils::hashPassword(newPlain);
}
