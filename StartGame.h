#pragma once
#include "Game.h"
#include "Console.h"
#include "UI.h"
#include "Grid.h"

class StartGame {
public:
	Game* game = nullptr;
	StartGame();
	void chooseGame();
	void launchGame();
};