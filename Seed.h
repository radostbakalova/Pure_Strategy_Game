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
* <Declares seed loading and saving>
*
*/
#pragma once
#include <string>
#include <fstream>
#include <iostream>

struct Seed {
	unsigned int value;
	void loadSeed(std::string fileName);
	void saveSeedOn(std::string fileName);
};