#include "Game.h"
using std::cout;
using std::cin;
using std::endl;

Game::Game(Player& p1, Player& p2) : player1(p1), player2(p2) {
}

size_t Game::inputChoice(Player& player) {
	size_t card;
	bool isFound = false;
	std::string input;
	std::getline(cin, input);
	while (!isFound) {
		while (true) {
			if (input == "A") {
				card = 1;
				break;
			}
			if (input == "2") {
				card = 2;
				break;
			}
			if (input == "3") {
				card = 3;
				break;
			}
			if (input == "4") {
				card = 4;
				break;
			}
			if (input == "5") {
				card = 5;
				break;
			}
			if (input == "6") {
				card = 6;
				break;
			}
			if (input == "7") {
				card = 7;
				break;
			}
			if (input == "8") {
				card = 8;
				break;
			}
			if (input == "9") {
				card = 9;
				break;
			}
			if (input == "10") {
				card = 10;
				break;
			}
			if (input == "J") {
				card = 11;
				break;
			}
			if (input == "D") {
				card = 12;
				break;
			}
			if (input == "K") {
				card = 13;
				break;
			}
			cout << "Invalid choice! Please try again." << endl;
			std::getline(cin, input);
		}
		for (size_t i = 0; i < player.remainingHands.getSize(); i++) {
			if (card == player.remainingHands.At(i)) {
				isFound = true;
				break;
			}
		}
		if (isFound) {
			break;
		}
		cout << "Invalid choice! Please try again." << endl;
		std::getline(cin, input);
	}
	return card;
}

void Game::recordGame(std::string& username, std::string& opponent, bool won1, bool won2, std::vector<UserProfile>& users) {
	for (UserProfile& user : users) {
		if (username == user.getUsername()) {
			user.recordGame(opponent, won1, won2);
		}
	}
}
