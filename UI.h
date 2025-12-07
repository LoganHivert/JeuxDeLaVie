#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Game.h"
#include "Console.h"
#include "GridGenerate.h"
#include "grid.h"
#include "View.h"
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "Bouton.h"
#include "GridSaveLoad.h"

class Grid;

class UI{
public :
    Grid grid;
    Cell* cell;
    GridGenerate gridGenerate;
    std::vector<sf::RectangleShape> gridLines;
    View Zoom;
    sf::RenderWindow window;
    Button* monBouton = nullptr;
    UI();
    void initializeWindow();
    void handleCellClick(Grid* grid, sf::RenderWindow& window, const sf::Event::MouseButtonPressed& mouse);
    void displayWindow(Grid* grid);
    int getPosXUi();
    int getPosYUi();
};

