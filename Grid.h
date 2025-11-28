#pragma once
#include "Cells.h"
#include <vector>

class Grid {
public:
    Grid(int cellSize, int rows, int cols);
    int cellSize;
    int rows;
    int cols;
    std::vector<std::vector<Cell>> cells;
    int getVoisinage(int x, int y);
    int getCell(int x, int y);
    int WindowsLength;
    int WindowsWidth;
};