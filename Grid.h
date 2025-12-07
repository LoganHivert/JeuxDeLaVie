#pragma once
#include "Cells.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
 //modifier car taille de la grille

class Grid {
public:
    Grid();
    int rows;
    int cols;
    // Grille vecteur
    std::vector<std::vector<Cell>> cells; 

    int getVoisinage(int x, int y);
    int getCell(int x, int y);
    int WindowsLength;//Ici c'est width / height, pas de windows, pas de taille > taille dans GridRenderer
    int WindowsWidth;
};