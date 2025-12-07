#pragma once
#include "Grid.h"
class GridSaveLoad{
public :
	GridSaveLoad();
	std::string file;
	void save(Grid* g);
	void saveVoid(Grid* g);
	void load(Grid* g);
private:
	Grid* grid;
};

