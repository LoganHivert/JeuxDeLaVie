#pragma once
#include <SFML/Graphics.hpp>
#include "grid.h"

class GridGenerate{
	public:
	GridGenerate();
	std::vector<sf::RectangleShape> createGridLines(Grid& grid);
};

