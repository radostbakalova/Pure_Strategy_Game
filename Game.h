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
* <Declares the main game logic and control of the game flow>
*
*/
#pragma once
#include "Player.h"
#include "UserProfile.h"

struct Game {
	Game(Player& p1, Player& p2);
	Player& player1;
	Player& player2;
	Deck rewardDeck;
	Deck currentReward;
	size_t inputChoice(Player& player);
	void recordGame(std::string& username, std::string& opponent, bool won1, bool won2, std::vector<UserProfile>& users);
	void decideWinner(std::vector<UserProfile>& users);
	bool isGameOver();
	void takeReward(Player& player);
	size_t playTurn(Player& player);
	void printPlayersCard(size_t card);
	void playRound();
	void playGame(unsigned int& seedValue, std::vector<UserProfile>& users);
};
