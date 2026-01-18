#pragma once
#include <string>
#include <fstream>
#include <iostream>

struct Seed {
	unsigned int value;
	void loadSeed(std::string fileName);
	void saveSeedOn(std::string fileName);
};