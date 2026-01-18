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
* <Declares management and storage of multiple user profiles>
*
*/
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