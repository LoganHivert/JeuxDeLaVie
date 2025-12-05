#pragma once
#include "Grid.h"
class GridSaveLoad{
public :
	GridSaveLoad(Grid* g);
	std::string file;
	void save();
	void saveVoid();
	void load();

private:
	Grid* grid; // ne possède pas la Grid


};

