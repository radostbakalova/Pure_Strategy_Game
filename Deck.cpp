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
