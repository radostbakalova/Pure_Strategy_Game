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
