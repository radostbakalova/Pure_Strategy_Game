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
