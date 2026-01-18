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

std::string UserManager::validatePassword(std::string& password, std::vector<UserProfile>& users) {
    while (true) {
        std::getline(cin, password);
        if (password.empty()) {
            cout << "Password cannot be empty! Please try again." << endl;
            cout << "Please enter valid password:" << endl;
            continue;
        }
        bool isValid = true;
        for (char symbol : password) {
            if (symbol == ' ') {
                cout << "Password cannot contain spaces! Please try again." << endl;
                cout << "Please enter valid password:" << endl;
                isValid = false;
                break;
            }
        }
        for (UserProfile user : users) {
            if (user.getPassword() == password) {
                cout << "This password is already taken! Please try again." << endl;
                cout << "Please enter valid password:" << endl;
                isValid = false;
                break;
            }
        }
        if (isValid) {
            break;
        }
    }
    return password;
}

void UserManager::registerUser(Player& player, std::vector<UserProfile>& users) {
    std::string username, password;
    cout << "Please enter username:" << endl;
    username = validateUsername(username, users);
    cout << "Please enter password:" << endl;
    password = validatePassword(password, users);
    users.push_back(UserProfile(username, password));
    player.username = username;
    player.isLogged = true;
    cout << "The profile was created successfully!" << endl;
}

void UserManager::loginUser(Player& player, std::vector<UserProfile>& users) {
    std::string username, password;
    size_t profileID;
    bool isFound = false;
    while (true) {
        cout << "Please enter your username:" << endl;
        while (true) {
            std::getline(cin, username);
            for (size_t i = 0; i < users.size(); i++) {
                if (users.at(i).getUsername() == username) {
                    profileID = i;
                    isFound = true;
                    break;
                }
            }
            if (isFound) {
                break;
            }
            cout << "Wrong username! Please try again." << endl;
        }
        cout << "Please enter your password:" << endl;
        std::getline(cin, password);
        while (users.at(profileID).getPassword() != password) {
            cout << "Wrong password! Please try again." << endl;
            std::getline(cin, password);
        }
        player.username = username;
        player.isLogged = true;
        cout << "Login successfull!" << endl;
        break;
    }
}

void UserManager::logoutUser(Player& player) {
    player.logoutPlayer();
}
