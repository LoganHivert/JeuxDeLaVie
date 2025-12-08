#include "Cells.h"
#include "Constantes.h"

Cell::Cell(int _x, int _y, bool al) {
	this->x = _x;
	this->y = _y;
	this->alive = al;

	shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
	shape.setPosition(sf::Vector2f(static_cast<float>(getPosX()*CELL_SIZE), static_cast<float>(getPosY()*CELL_SIZE)));
	shape.setFillColor(sf::Color::Black); // cell morte
	/*shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color(150, 0, 0));*/
}

int Cell::getPosX() {
	return (this->x);
}

int Cell::getPosY() {
	return (this->y);
}