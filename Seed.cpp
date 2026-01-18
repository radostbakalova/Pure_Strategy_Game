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
* <Implements seed loading and saving>
*
*/
#include "Seed.h"
using std::cout;
using std::endl;

void Seed::loadSeed(std::string fileName) {
	std::ifstream input = std::ifstream(fileName);
	if (!input.is_open()) {
		return;
	}
	if (!input.good()) {
		cout << "Could not read the seed file! Please restart the program." << endl;
	}
	input >> value;
	input.close();
}

void Seed::saveSeedOn(std::string fileName) {
	std::ofstream output = std::ofstream(fileName);
	if (!output.is_open()) {
		cout << "Program failed save new seed!" << endl;
	}
	output << value;
	output.close();
}