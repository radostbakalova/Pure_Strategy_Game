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
* <Declares user management functionality>
*
*/
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
