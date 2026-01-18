#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>

struct Deck {
	std::vector<size_t> deck;
	size_t getSize();
	size_t At(size_t position);
	void initialize();
	void shuffle(unsigned int& seedValue);
	size_t drawTopCard();
	void removeCard(size_t value);
	void addCard(size_t value);
	bool isEmpty();
	void printDeck();
	void emptyDeck();
};
