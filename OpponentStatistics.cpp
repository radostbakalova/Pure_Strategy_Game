#include "OpponentStatistics.h"
using std::cout;
using std::endl;

const int IGNORE_LIMIT = 1000;

size_t OpponentStatistics::getSize() {
	return statistics.size();
}
