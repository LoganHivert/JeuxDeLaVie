#pragma once
#include "Cells.h"
class Grid {
public:
    Grid(int cellSize, int rows, int cols);
    int cellSize;
    int rows;
    int cols;

    int WindowsLength;
    int WindowsWidth;
};