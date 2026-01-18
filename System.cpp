/**
*
* Solution to course project # 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Radost Bakalova
* @idnumber 2MI0600667
* @compiler VC
*
* <Implements core system logic>
*
*/
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

size_t System::managePlayerChoice() {
	showPlayerMenu();
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
		cout << "Invalid input! Please try again." << endl;
	}
	return choice;
}

void System::run() {
	cout << "< THE GAME OF PURE STRATEGY >" << endl;
	Seed seed;
	seed.loadSeed("seed.txt");
	data.loadFileData("data.txt");
	while (true) {
		size_t choice;
		if (!player1.isLogged) {
			manager.managePlayer(player1, data.users);
		}
		if (!player2.isLogged) {
			manager.managePlayer(player2, data.users);
		}
		Game game(player1, player2);
		choice = manageGameChoice();
		switch (choice) {
		case 1: game.playGame(seed.value, data.users);
			break;
		case 2: choice = managePlayerChoice();
			if (choice == 1) {
				data.printUserStatistics(player1.username);
				break;
			}
			if (choice == 2) {
				data.printUserStatistics(player2.username);
				break;
			}
			data.printUserStatistics(player1.username);
			data.printUserStatistics(player2.username);
			break;
		case 3: choice = managePlayerChoice();
			if (choice == 1) {
				manager.logoutUser(player1);
				break;
			}
			if (choice == 2) {
				manager.logoutUser(player2);
				break;
			}
			manager.logoutUser(player1);
			manager.logoutUser(player2);
			break;
		case 4: data.saveDataOn("data.txt");
			seed.saveSeedOn("seed.txt");
			std::exit(0);
		default: cout << "Failed to load game option! Please restart the program." << endl;
		}
	}
}