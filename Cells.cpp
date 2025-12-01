#include "Cells.h"

Cell::Cell(int _x, int _y) {
	this->x = _x;
	this->y = _y;
	this->alive = 0;

	shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	shape.setPosition(sf::Vector2f(static_cast<float>(getPosX()), static_cast<float>(getPosY())));
	shape.setFillColor(sf::Color::Black); // cell morte
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color(150, 150, 150));
}

int Cell::getPosX(){
	return (this->x * CELL_SIZE);
}

int Cell::getPosY() {
	return (this->y * CELL_SIZE);
}