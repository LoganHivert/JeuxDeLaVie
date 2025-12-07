#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "View.h"
#include "UIRun.h"

class UIRun;

class Controls{
public:
	std::optional<sf::Event> event;
	std::optional<GridSaveLoad> Gload;
	Controls();
	void checkControls(UIRun& UiR);
};

