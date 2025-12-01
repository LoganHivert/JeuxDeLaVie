#pragma once
#include <SFML/Graphics.hpp>
const int CELL_SIZE = 30;

class Cell {
public:
	Cell(int _x, int _y, int al);
	int alive;
	int getPosXUi();
	int getPosYUi();
	int getPosX();
	int getPosY();
	sf::RectangleShape shape;
private:
	int x;
	int y;
};