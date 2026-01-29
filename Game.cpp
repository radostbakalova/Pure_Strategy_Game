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
* <Implements the main game logic and control of the game flow>
*
*/
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
			if (input == "Q") {
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

size_t Game::playTurn(Player& player) {
	cout << endl;
	cout << "The current reward is:" << endl;
	currentReward.printDeck();
	cout << "Reward cards you have collected:" << endl;
	player.rewardCardsCollected.printDeck();
	cout << player.username << ", please choose a card:" << endl;
	player.remainingHands.printDeck();
	size_t card = inputChoice(player);
	player.remainingHands.removeCard(card);
	return card;
}

void Game::printPlayersCard(size_t card) {
	if (card == 1) {
		cout << 'A';
		return;
	}
	if (card == 11) {
		cout << 'J';
		return;
	}
	if (card == 12) {
		cout << 'Q';
		return;
	}
	if (card == 13) {
		cout << 'K';
		return;
	}
	cout << card;
}

void Game::playRound() {
	size_t rewardCard = rewardDeck.drawTopCard();
	currentReward.addCard(rewardCard);
	size_t card1 = playTurn(player1);
	size_t card2 = playTurn(player2);
	cout << player1.username << "'s card: ";
	printPlayersCard(card1);
	cout << endl;
	cout << player2.username << "'s card: ";
	printPlayersCard(card2);
	cout << endl;
	if (card1 > card2) {
		takeReward(player1);
		return;
	}
	if (card1 < card2) {
		takeReward(player2);
		return;
	}
	if (!isGameOver()) {
		cout << "Both players picked the same card!" << endl
			<< "Play another round to decide who takes the previous and the next card(s)." << endl;
		return;
	}
	cout << endl;
}

void Game::playGame(unsigned int& seedValue, std::vector<UserProfile>& users) {
	cout << endl;
	cout << "Let the game begin!" << endl;
	rewardDeck.initialize();
	rewardDeck.shuffle(seedValue);
	player1.remainingHands.initialize();
	player2.remainingHands.initialize();
	while (!isGameOver()) {
		playRound();
	}
	cout << "The game is over!" << endl;
	decideWinner(users);
}