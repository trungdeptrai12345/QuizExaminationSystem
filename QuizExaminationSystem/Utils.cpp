#include "Utils.h"
#include <iostream>
#include <limits>
#include <functional>

using namespace std;

string Utils::readString(const string& msg) {
    string s;
    do {
        cout << msg;
        getline(cin, s);
    } while (s.empty());
    return s;
}

int Utils::readInt(const string& msg, int min, int max) {
    int x;
    while (true) {
        cout << msg;
        if (cin >> x && x >= min && x <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Gia tri khong hop le. Thu lai!\n";
    }
}

string Utils::hashPassword(const string& plain) {
    hash<string> h;
    return to_string(h(plain));
}
