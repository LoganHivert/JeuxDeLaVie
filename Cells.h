#pragma once
#include <SFML/Graphics.hpp>
const int CELL_SIZE = 30;//dans grille renderer

class Cell {
public:
	Cell(int _x, int _y, bool al);
	bool alive;
	int getPosX();
	int getPosY();
	sf::RectangleShape shape;
private:
	int x;
	int y;
};