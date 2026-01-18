#include "Statistic.h"
using std::cout;
using std::endl;

Statistic::Statistic() {
	this->opponentName = "";
	this->gamesPlayed = 0;
	this->gamesWon = 0;
}

Statistic::Statistic(std::string& opponentName, size_t gamesPlayed, size_t gamesWon) {
	this->opponentName = opponentName;
	this->gamesPlayed = gamesPlayed;
	this->gamesWon = gamesWon;
}
