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
#include "Buttons.h"
#include "GridSaveLoad.h"

class Grid;

class UI{
public :
    Cell* cell;
    GridGenerate gridGenerate;
    sf::RectangleShape gridBackground;
    std::vector<sf::RectangleShape> gridLines;
    View* Zoom;
    sf::RenderWindow window;
    sf::View initialView;
    Button* myButton = nullptr;
    UI();
    void initializeWindow(Grid* grid);
    void handleCellClick(Grid* grid, sf::RenderWindow& window, const sf::Event::MouseButtonPressed& mouse);
    void displayWindow(Grid* grid);
    int getPosXUi();
    int getPosYUi();
    void CheckGridColor(Grid* grid);
};

