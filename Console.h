#pragma once
#include "Game.h"
#include <string>
#include <iostream>

class Console {
public:
	Console(Game* g);
	void menu();
	void play(int a);
	void load(std::string n);
	void save();
private:
	Game* game;
};