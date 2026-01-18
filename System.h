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