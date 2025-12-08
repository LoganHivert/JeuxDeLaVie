#pragma once
#include"Cells.h"
#include "Grid.h"
const int MiniLawAlive = 2; // modifier le nombre mini de voisins pour la survie
const int MaxiLawAlive = 3; // modifier le nombre maxi de voisins pour la survie
const int MiniLawDead = 3; // modifier le nombre de voisins pour la naissance

class Grid;
class Game {
public:
	Game();
	std::vector<Cell> tempChange;
	void checkGrid(Grid* grid);
	void LawAlive(int x, int y, Grid* grid);
	void LawDead(int x, int y, Grid* grid);
	void randomizeGrid(Grid* grid);
	void play(int a, Grid* grid);
	void setSpeed(float coef);
	int getSpeed();
private:
	int speed{ 1 };
};