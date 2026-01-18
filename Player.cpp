#include "Player.h"

Player::Player(size_t ID) {
	this->username = "";
	this->isLogged = false;
	this->ID = ID;
	this->score = 0;
}

void Player::resetPlayerHands() {
	score = 0;
	remainingHands.emptyDeck();
	rewardCardsCollected.emptyDeck();
}