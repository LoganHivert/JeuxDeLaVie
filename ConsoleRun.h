#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Grid.h"
#include "Game.h"
#include "GridSaveLoad.h"

class ConsoleRun{
public:
	Grid* grid;
	Game* game;
	GridSaveLoad* Gload;
	bool Run;
	void gameRun();
};