#pragma once
#include "Cells.h"
#include <vector>
const int ROWS = 100; 
const int COLS = 100;

class Grid {
public:
    Grid();

    // Grille vecteur
    std::vector<std::vector<Cell>> cells; 

    int getVoisinage(int x, int y);
    int getCell(int x, int y);
    int WindowsLength;//Ici c'est width / height, pas de windows, pas de taille > taille dans GridRenderer
    int WindowsWidth;
};