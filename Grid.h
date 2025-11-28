#pragma once
#include "Cells.h"
#include <vector>

class Grid {
public:
    Grid(int rows, int cols);
    int rows;
    int cols;
  
    // Grille logique
    std::vector<std::vector<Cell>> cells;

    // Grille graphique
    std::vector<sf::RectangleShape> cellGraph;

    int getVoisinage(int x, int y);
    int getCell(int x, int y);
    int WindowsLength;
    int WindowsWidth;
};