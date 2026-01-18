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

void UserManager::managePlayer(Player& player, std::vector<UserProfile>& users) {
    showLoginMenu(player);
    size_t choice;
    std::string input;
    while (true) {
        std::getline(cin, input);
        if (cin.fail()) {
            cin.clear();
            cin.ignore(IGNORE_LIMIT, '\n');
            continue;
        }
        if (input.size() > 1) {
            cout << "Invalid input! Please try again." << endl;
            continue;
        }
        if (input[0] == '1') {
            choice = 1;
            break;
        }
        if (input[0] == '2') {
            choice = 2;
            break;
        }
        cout << "Invalid input! Please try again." << endl;
    }
    if (choice == 1) {
        registerUser(player, users);
        return;
    }
    if (choice == 2) {
        loginUser(player, users);
        return;
    }
    cout << "Failed to perform the action! Please restart the program." << endl;
}