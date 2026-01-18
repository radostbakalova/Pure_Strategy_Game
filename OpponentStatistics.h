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
