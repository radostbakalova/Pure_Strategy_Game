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
