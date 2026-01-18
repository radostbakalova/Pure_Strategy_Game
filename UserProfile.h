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
* <Declares functionality for a single user profile and its data>
*
*/
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