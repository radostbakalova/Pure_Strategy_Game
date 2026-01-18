#pragma once
#include <string>
#include <vector>
#include "OpponentStatistics.h"
#include <cmath>

struct UserProfile {
	UserProfile();
	UserProfile(std::string& username, std::string& password);
	std::string getUsername();
	std::string getPassword();
	void recordGame(std::string& opponent, bool won1, bool won2);
	void printStatistics();
	void loadFromFile(std::ifstream&);
	void saveFileData(std::ofstream&);
private:
	std::string username;
	std::string password;
	size_t totalGamesPlayed;
	size_t totalGamesWon;
	OpponentStatistics opponentStatistics;
};