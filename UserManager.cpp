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
