#include "OpponentStatistics.h"
using std::cout;
using std::endl;

const int IGNORE_LIMIT = 1000;

size_t OpponentStatistics::getSize() {
	return statistics.size();
}

void OpponentStatistics::add(Statistic stat) {
	statistics.push_back(stat);
}

bool OpponentStatistics::exist(std::string& username) {
	for (size_t i = 0; i < statistics.size(); i++) {
		if (username == statistics.at(i).opponentName) {
			return true;
		}
	}
	return false;
}

void OpponentStatistics::recordGame(std::string& opponent, bool won1) {
	for (size_t i = 0; i < statistics.size(); i++) {
		if (opponent == statistics.at(i).opponentName) {
			(statistics.at(i).gamesPlayed)++;
			if (won1) {
				(statistics.at(i).gamesWon++);
			}
		}
	}
}

void OpponentStatistics::loadFileData(std::ifstream& input) {
	if (!input.good()) {
		cout << "Could not open file." << endl;
		return;
	}
	size_t size;
	input >> size;
	if (size == 0) {
		return;
	}
	statistics.resize(size);
	for (Statistic& stat : statistics) {
		stat.loadFromFile(input);
	}
}

void OpponentStatistics::printStatistics() {
	for (Statistic& stat : statistics) {
		stat.printStatistic();
	}
	cout << endl;
}

void OpponentStatistics::saveFileData(std::ofstream& output) {
	if (!output.good()) {
		cout << "File is not good for writing." << endl;
		return;
	}
	for (Statistic stat : statistics) {
		output << stat.opponentName << endl;
		output << stat.gamesPlayed << endl;
		output << stat.gamesWon << endl;
	}
}