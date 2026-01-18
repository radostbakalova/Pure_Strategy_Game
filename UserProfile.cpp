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
* <Implements functionality for a single user profile and its data>
*
*/
#include "UserProfile.h"
using std::cout;
using std::endl;

const int IGNORE_LIMIT = 1000;

UserProfile::UserProfile() {
	this->username = "";
	this->password = "";
	this->totalGamesPlayed = 0;
	this->totalGamesWon = 0;
}

UserProfile::UserProfile(std::string& username, std::string& password) {
	this->username = username;
	this->password = password;
	totalGamesPlayed = 0;
	totalGamesWon = 0;
}

std::string UserProfile::getUsername() {
	return username;
}

std::string UserProfile::getPassword() {
	return password;
}

void UserProfile::recordGame(std::string& currentOpponent, bool won1, bool won2) {
	this->totalGamesPlayed++;
	if (won1) {
		this->totalGamesWon++;
	}
	if (opponentStatistics.exist(currentOpponent)) {
		opponentStatistics.recordGame(currentOpponent, won1);
		return;
	}
	size_t result = won1 ? 1 : 0;
	opponentStatistics.add(Statistic(currentOpponent, 1, result));
}

void UserProfile::printStatistics() {
	cout << "Username: " << username << endl;
	if (totalGamesPlayed == 0) {
		cout << "Total games played: 0" << endl
			<< "Total games won: 0 (0%)" << endl
			<< "Games against other players (wins/%):" << endl
			<< "There are no statistics." << endl << endl;
		return;
	}
	cout << "Total games played: " << totalGamesPlayed << endl;
	double wonGamesPercent = ((double)totalGamesWon) / ((double)totalGamesPlayed);
	wonGamesPercent = std::round(wonGamesPercent * 100) / 100;
	cout << "Total games won: " << totalGamesWon << " (" << wonGamesPercent << "%)" << endl;
	cout << "Games against other players (wins/%):" << endl;
	opponentStatistics.printStatistics();
}

void UserProfile::loadFromFile(std::ifstream& input) {
	if (!input.good()) {
		cout << "Could not open file." << endl;
		return;
	}
	input >> username;
	input >> password;
	input >> totalGamesPlayed;
	input >> totalGamesWon;
	opponentStatistics.loadFileData(input);
}

void UserProfile::saveFileData(std::ofstream& output) {
	if (!output.good()) {
		cout << "File is not good for writing." << endl;
		return;
	}
	output << username << endl;
	output << password << endl;
	output << totalGamesPlayed << endl;
	output << totalGamesWon << endl;
	output << opponentStatistics.getSize() << endl;
	opponentStatistics.saveFileData(output);
	output << endl;
}