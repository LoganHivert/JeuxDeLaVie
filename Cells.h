#pragma once
#define CELL_SIZE 30//test

class Cell {
public:
	Cell(int _x, int _y);
	bool alive;
	int getPosX();
	int getPosY();
private:
	int x;
	int y;
};