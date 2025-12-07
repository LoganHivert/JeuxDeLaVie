#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "View.h"
#include "UIRun.h"

class Controls{
public:
	std::optional<sf::Event> event;
	UI ui;
	std::optional<GridSaveLoad> Gload;
	Grid grid;
	View Zoom;
	Controls();
	void checkControls(UIRun& UiR);
};

