#pragma once
#include "Game.h"
#include <fstream>
#include <string>
#include <iostream>
class Game;
class Console : public Game {
public:
	Console();
	int menu();
	void gameRun() override;
};