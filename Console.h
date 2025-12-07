#pragma once
#include "Game.h"
#include <fstream>
#include <string>
#include <iostream>

class Console{
public:
	Grid grid;
	Game game;
	Console();
	int menu();
};