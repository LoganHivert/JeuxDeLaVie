#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Grid.h"
#include "Game.h"
#include "GridSaveLoad.h"

class ConsoleRun{
public:
	Game* game;
	GridSaveLoad* Gload;
	Grid* grid;
	bool Run;
	void gameRun(Grid* _grid);
};