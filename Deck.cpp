#include "Deck.h"
using std::cout;
using std::endl;

const int MAX_SIZE_OF_DECK = 13;

size_t Deck::getSize() {
	return deck.size();
}

size_t Deck::At(size_t position) {
	return deck.at(position);
}

void Deck::initialize() {
	int cardValue = 1;
	for (size_t i = 0; i < MAX_SIZE_OF_DECK; i++) {
		deck.push_back(cardValue++);
	}
}

void Deck::shuffle(unsigned int& seedValue) {
	srand(seedValue);
	for (size_t i = MAX_SIZE_OF_DECK - 1; i > 0; i--) {
		size_t positionToSwap = rand() % (i + 1);
		size_t temporaryValue = deck.at(i);
		deck.at(i) = deck.at(positionToSwap);
		deck.at(positionToSwap) = temporaryValue;
	}
	seedValue++;
}

size_t Deck::drawTopCard() {
	size_t topCard = deck.front();
	deck.erase(deck.begin());
	return topCard;
}

void Deck::removeCard(size_t value) {
	for (size_t i = 0; i < deck.size(); i++) {
		if (deck.at(i) == value) {
			deck.erase(deck.begin() + i);
			return;
		}
	}
}
