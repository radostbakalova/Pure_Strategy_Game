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
* <Implements functionality for a single player and state during the game>
*
*/
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

void Player::logoutPlayer() {
	username = "";
	score = 0;
	isLogged = false;
}