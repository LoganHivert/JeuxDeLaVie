#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Console.h"
#include "GridGenerate.h"
#include "grid.h"
#include "View.h"
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "Bouton.h"

class Grid;

class UI: public Game{
public :
    Cell* cell;
    GridGenerate gridGenerate;
    std::vector<sf::RectangleShape> gridLines;
    sf::View view;
    View Zoom;
    sf::RenderWindow window;
    Button* monBouton = nullptr;
    bool Run;

    UI();
    void initializeWindow();
    void handleCellClick(Grid* grid, sf::RenderWindow& window, const sf::Event::MouseButtonPressed& mouse);
    void displayWindow(sf::RenderWindow& window, Grid* grid);
    void gameRun() override;
    int getPosXUi();
    int getPosYUi();
};

