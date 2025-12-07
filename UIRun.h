#pragma once
#include "ConsoleRun.h"
#include "UI.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

class UIRun : public ConsoleRun {
public:
	UI ui;
	Grid* grid;
	void gameRun(Grid* _grid);
	void gameSpeed();
};