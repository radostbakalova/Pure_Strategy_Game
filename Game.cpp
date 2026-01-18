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

void Game::decideWinner(std::vector<UserProfile>& users) {
	cout << player1.username << "'s score: " << player1.score << endl;
	cout << player2.username << "'s score: " << player2.score << endl;
	bool p1won, p2won;
	if (player1.score > player2.score) {
		p1won = true;
		p2won = false;
		cout << player1.username << " won and "
			<< player2.username << " lost! Good game!" << endl << endl;
	}
	if (player1.score < player2.score) {
		p1won = false;
		p2won = true;
		cout << player2.username << " won and "
			<< player1.username << " lost! Good game!" << endl << endl;
	}
	if (player1.score == player2.score) {
		p1won = false;
		p2won = false;
		cout << "Draw!" << endl << endl;
	}
	recordGame(player1.username, player2.username, p1won, p2won, users);
	recordGame(player2.username, player1.username, p2won, p1won, users);
	player1.resetPlayerHands();
	player2.resetPlayerHands();
}

bool Game::isGameOver() {
	size_t deck1 = player1.remainingHands.getSize();
	size_t deck2 = player2.remainingHands.getSize();
	if (deck1 == 0 || deck2 == 0) {
		return true;
	}
	return false;
}

void Game::takeReward(Player& player) {
	cout << player.username << " gets the hand!" << endl;
	cout << endl;
	for (size_t i = 0; i < currentReward.getSize(); i++) {
		size_t rewardCard = currentReward.At(i);
		player.rewardCardsCollected.addCard(rewardCard);
		player.score += rewardCard;
	}
	currentReward.emptyDeck();
}
