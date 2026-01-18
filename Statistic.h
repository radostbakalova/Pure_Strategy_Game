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
* <Declares tracking and handling of statistics for one game opponent>
*
*/
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