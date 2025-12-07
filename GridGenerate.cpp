#include "GridGenerate.h"
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "Constantes.h"

// Initialisation de la grille

std::vector<sf::RectangleShape> GridGenerate::createGridLines(Grid& grid){
    std::vector<sf::RectangleShape> gridLines;
    // Lignes verticales
    for (float x = 0; x <= COLS; ++x) {
        float px = x * CELL_SIZE;
        sf::RectangleShape line(sf::Vector2f(1.f, static_cast<float>(grid.WindowsLength)));
        line.setPosition(sf::Vector2f(px, 0.f));
        line.setFillColor(sf::Color(150, 150, 150));
        gridLines.push_back(line);
    }

    // Lignes horizontales
    for (float y = 0; y <= ROWS; ++y) {
        float py = y * CELL_SIZE;
        sf::RectangleShape line(sf::Vector2f(static_cast<float>(grid.WindowsWidth), 1.f));
        line.setPosition(sf::Vector2f(0.f, py));
        line.setFillColor(sf::Color(150, 150, 150));
        gridLines.push_back(line);
    }

    return gridLines;
}

GridGenerate::GridGenerate(){}



