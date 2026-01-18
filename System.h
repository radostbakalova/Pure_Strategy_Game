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
* <Declares core system logic>
*
*/
#pragma once
#include "Seed.h"
#include "UserProfiles.h"
#include "UserManager.h"
#include "Game.h"

struct System {
	void showGameMenu();
	void showPlayerMenu();
	size_t manageGameChoice();
	size_t managePlayerChoice();
	void run();
private:
	UserProfiles data;
	UserManager manager;
	Player player1 = Player(1);
	Player player2 = Player(2);
};