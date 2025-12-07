#pragma once
#include "ConsoleRun.h"
#include "UI.h"
#include <SFML/Graphics.hpp>

class UIRun : public ConsoleRun {
public:
	UI ui;
	void gameRun();
};