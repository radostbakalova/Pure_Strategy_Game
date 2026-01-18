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
