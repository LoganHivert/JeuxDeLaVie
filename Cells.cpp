#include "Cells.h"

Cell::Cell(int _x, int _y, int al) {
	this->x = _x;
	this->y = _y;
	this->alive = al;

	shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	shape.setPosition(sf::Vector2f(static_cast<float>(getPosX()), static_cast<float>(getPosYUi())));
	shape.setFillColor(sf::Color::Black); // cell morte
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color(150, 150, 150));
}

int Cell::getPosXUi(){
	return (this->x * CELL_SIZE);
}

int Cell::getPosYUi() {
	return (this->y * CELL_SIZE);
}

int Cell::getPosX() {
	return (this->x);
}

int Cell::getPosY() {
	return (this->y);
}