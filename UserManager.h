#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "UserProfiles.h"

struct UserManager {
	void showLoginMenu(Player& player);
	std::string validateUsername(std::string& username,std::vector<UserProfile>& users);
	std::string validatePassword(std::string& username, std::vector<UserProfile>& users);
	void registerUser(Player& player, std::vector<UserProfile>& users);
	void loginUser(Player& player, std::vector<UserProfile>& users);
	void logoutUser(Player& player);
	void managePlayer(Player& player, std::vector<UserProfile>& users);
};
