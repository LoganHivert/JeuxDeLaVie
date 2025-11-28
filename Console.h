#pragma once
class Game;
#include <fstream>
#include <string>
#include <iostream>

class Console {
public:
	Console(Game* g);
	void menu();
	void play(int a);
	void load();
	void save();
private:
	Game* game;
};