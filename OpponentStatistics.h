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
* <Declares tracking and handling of statistics for game opponents>
*
*/
#pragma once
#include <string>
#include <vector>
#include "Statistic.h"
#include <iostream>
#include <fstream>

struct OpponentStatistics {
	size_t getSize();
	void add(Statistic stat);
	bool exist(std::string& username);
	void recordGame(std::string& opponent, bool result);
	void loadFileData(std::ifstream& input);
	void printStatistics();
	void saveFileData(std::ofstream& output);
private:
	std::vector<Statistic> statistics;
};
