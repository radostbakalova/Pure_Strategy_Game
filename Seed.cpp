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