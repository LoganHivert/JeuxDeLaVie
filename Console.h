#pragma once
class Game;
#include <fstream>
#include <string>
#include <iostream>

class Console {
public:
	std::string file;
	Console(Game* g);
	void saveVoid();
	void menu();
	void play(int a);
	void load();
	void save();
private:
	Game* game;
};