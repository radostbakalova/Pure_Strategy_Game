#pragma once
#include <string>
#include <fstream>
#include <iostream>

struct Statistic {
	std::string opponentName;
	size_t gamesPlayed;
	size_t gamesWon;
	Statistic();
	Statistic(std::string& opponentName, size_t gamesPlayed, size_t gamesWon);
	void printStatistic();
	void loadFromFile(std::ifstream& input);
};