#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <algorithm>
using namespace std;

class TApplication {
public:
    void Run() {
        int n = 0;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            string command;
            cin >> command;

            if (command == "register") {
                string username, password;
                cin >> username >> password;
                Register(username, password);
            } else if (command == "login") {
                string username, password;
                cin >> username >> password;
                Login(username, password);
            } else {
                string username;
                cin >> username;
                Logout(username);
            }
        }

    }
private:
    unordered_map<string, string> Username2Password;
    unordered_set<string> LoggedInUsers;
private:
    void Register(const string& username, const string& password) {
        const auto it = Username2Password.find(username);
        if (it != Username2Password.end()) {
            cout << "fail: user already exists" << endl;
        } else {
            Username2Password.insert(make_pair(username, password));
            cout << "success: new user added" << endl;
        }
    }

    void Login(const string& username, const string& password) {
        const auto it = Username2Password.find(username);
        const auto lit = LoggedInUsers.find(username);
        if (it == Username2Password.end()) {
            cout << "fail: no such user" << endl;
        } else if (it->second != password) {
            cout << "fail: incorrect password" << endl;
        } else if (lit != LoggedInUsers.end()) {
            cout << "fail: already logged in" << endl;
        } else {
            LoggedInUsers.insert(username);
            cout << "success: user logged in" << endl;
        }
    }

    void Logout(const string& username) {
        const auto it = Username2Password.find(username);
        const auto lit = LoggedInUsers.find(username);
        if (it == Username2Password.end()) {
            cout << "fail: no such user" << endl;
        } else if (lit == LoggedInUsers.end()) {
            cout << "fail: already logged out" << endl;
        } else {
            LoggedInUsers.erase(lit);
            cout << "success: user logged out" << endl;
        }
    }
};

int main() {
    TApplication application;
    application.Run();
    return 0;
}
