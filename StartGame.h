#pragma once
#include "Game.h"
#include "ConsoleRun.h"
#include "UIRun.h"
#include "Grid.h"


class StartGame {
public:
	ConsoleRun* gameCons = nullptr;
	UIRun* gameUi = nullptr;
	Grid* grid;
	bool Gtype;
	StartGame();
	void chooseGame();
	void launchGame();
};