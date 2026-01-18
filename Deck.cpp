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