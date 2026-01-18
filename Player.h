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
* <Declares functionality for a single player and state during the game>
*
*/
#pragma once
#include <string>
#include "Deck.h"

struct Player {
	Player(size_t ID);
	std::string username;
	bool isLogged;
	size_t ID;
	Deck remainingHands;
	Deck rewardCardsCollected;
	size_t score;
	void resetPlayerHands();
	void logoutPlayer();
};