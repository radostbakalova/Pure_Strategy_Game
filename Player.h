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