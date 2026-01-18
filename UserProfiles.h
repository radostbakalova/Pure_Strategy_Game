#pragma once
#include <vector>
#include "UserProfile.h"
#include "Player.h"
#include <fstream>
#include <iostream>

struct UserProfiles {
	std::vector<UserProfile> users;
	void loadFileData(std::string fileName);
	void printUserStatistics(std::string username);
	void saveDataOn(std::string fileName);
};