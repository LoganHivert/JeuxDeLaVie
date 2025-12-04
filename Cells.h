#pragma once
#include <SFML/Graphics.hpp>
const int CELL_SIZE = 30;//dans grille renderer

class Cell {
public:
	Cell(int _x, int _y, int al);
	int alive;//NON c un boolean
	int getPosXUi();//NON rien a faire ici
	int getPosYUi();//NON rien a faire ici
	int getPosX();
	int getPosY();
	sf::RectangleShape shape;
private:
	int x;
	int y;
};