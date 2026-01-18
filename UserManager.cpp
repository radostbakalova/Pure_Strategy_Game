#include "UserManager.h"
using std::cout;
using std::cin;
using std::endl;

const int IGNORE_LIMIT = 1000;

void UserManager::showLoginMenu(Player& player) {
    cout << "Please select an option for Player " << player.ID << ": " << endl
        << "| 1 - Register" << endl
        << "| 2 - Log in" << endl;
}

std::string UserManager::validateUsername(std::string& username, std::vector<UserProfile>& users) {
    while (true) {
        std::getline(cin, username);
        if (username.empty()) {
            cout << "Username cannot be empty! Please try again." << endl;
            cout << "Please enter valid username:" << endl;
            continue;
        }
        bool isValid = true;
        for (char symbol : username) {
            if (symbol == ' ') {
                cout << "Username cannot contain spaces! Please try again." << endl;
                cout << "Please enter valid username:" << endl;
                isValid = false;
                break;
            }
        }
        for (UserProfile user : users) {
            if (user.getUsername() == username) {
                cout << "This username is already taken! Please try again." << endl;
                cout << "Please enter valid username:" << endl;
                isValid = false;
                break;
            }
        }
        if (isValid) {
            break;
        }
    }
    return username;
}
