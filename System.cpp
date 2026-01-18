#include "System.h"
using std::cout;
using std::cin;
using std::endl;

const int IGNORE_LIMIT = 1000;

void System::showGameMenu() {
	cout << "Please select an option: " << endl
		<< "| 1 - Play game" << endl
		<< "| 2 - Load statistics" << endl
		<< "| 3 - Log out" << endl
		<< "| 4 - Quit game" << endl;
}

void System::showPlayerMenu() {
	cout << "Please select for which player:" << endl
		<< "| 1 - " << player1.username << endl
		<< "| 2 - " << player2.username << endl
		<< "| 3 - Both" << endl;
}

size_t System::manageGameChoice() {
	showGameMenu();
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
		if (input[0] == '3') {
			choice = 3;
			break;
		}
		if (input[0] == '4') {
			choice = 4;
			break;
		}
		cout << "Invalid input! Please try again." << endl;
	}
	return choice;
}
