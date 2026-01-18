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
* <Implements management and storage of multiple user profiles>
*
*/
#include "UserProfiles.h"
using std::cout;
using std::endl;

const int IGNORE_LIMIT = 1000;

void UserProfiles::loadFileData(std::string fileName) {
	std::ifstream input = std::ifstream(fileName);
	if (!input.is_open()) {
		return;
	}
	if (!input.good()) {
		std::cout << "Could not load the users! Please restart the program." << endl;
	}
	size_t size;
	input >> size;
	users.resize(size);
	for (UserProfile& user : users) {
		user.loadFromFile(input);
	}
	input.close();
}

void UserProfiles::printUserStatistics(std::string username) {
	for (size_t i = 0; i < users.size(); i++) {
		if (username == users.at(i).getUsername()) {
			users.at(i).printStatistics();
			return;
		}
	}
	cout << "Could not load the statistics! Please restart the program." << endl;
}

void UserProfiles::saveDataOn(std::string fileName) {
	std::ofstream output = std::ofstream(fileName);
	if (!output.is_open()) {
		std::cout << "Data could not save in the file." << endl;
		return;
	}
	output << users.size() << endl;
	for (UserProfile user : users) {
		user.saveFileData(output);
	}
	output.close();
}