#pragma once
#include"Cells.h"
const int MiniLawAlive = 2; // modifier le nombre mini de voisins pour la survie
const int MaxiLawAlive = 3; // modifier le nombre maxi de voisins pour la survie
const int MiniLawDead = 3; // modifier le nombre de voisins pour la naissance

class Grid;
class Game {
public:
	Game(Grid* g);
	std::vector<Cell> tempChange;
	std::string file;
	void checkGrid();
	void LawAlive(int x, int y);
	void LawDead(int x, int y);
	void randomizeGrid();
	void saveVoid();
	void play(int a);
	void load();
	void save();
	virtual void gameRun();
	Grid* grid;
};