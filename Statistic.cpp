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
* <Implements tracking and handling of statistics for one game opponent>
*
*/
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

void Statistic::printStatistic() {
	double wonGamesPercent = ((double)gamesWon) / ((double)gamesPlayed);
	int firstFourDigits = wonGamesPercent * 10000;
	wonGamesPercent = firstFourDigits;
	wonGamesPercent /= 100;
	cout << "- " << opponentName << ": " <<
		gamesPlayed << " games played (" <<
		gamesWon << "/" << wonGamesPercent << "% wins)" << endl;
}

void Statistic::loadFromFile(std::ifstream& input) {
	if (!input.good()) {
		cout << "Could not open file." << endl;
		return;
	}
	input >> opponentName;
	input >> gamesPlayed;
	input >> gamesWon;
}