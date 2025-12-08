#include "GridGenerate.h"
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "Constantes.h"
#include <cmath>

std::vector<sf::RectangleShape> GridGenerate::createGridLines(Grid& grid) {
    std::vector<sf::RectangleShape> gridLines;
    // Lignes verticales
    for (float x = 0; x <= grid.cols; ++x) {
        float px = x * CELL_SIZE;
        sf::RectangleShape line(sf::Vector2f(1.f, static_cast<float>(grid.WindowsLength)));
        line.setPosition(sf::Vector2f(px, 0.f));
        line.setFillColor(sf::Color(150, 150, 150));
        gridLines.push_back(line);
    }
    // Lignes horizontales
    for (float y = 0; y <= grid.rows; ++y) {
        float py = y * CELL_SIZE;
        sf::RectangleShape line(sf::Vector2f(static_cast<float>(grid.WindowsWidth), 1.f));
        line.setPosition(sf::Vector2f(0.f, py));
        line.setFillColor(sf::Color(150, 150, 150));
        gridLines.push_back(line);
    }
    return gridLines;
}

void GridGenerate::updateGridLinesThickness(std::vector<sf::RectangleShape>& gridLines,
    Grid& grid, float zoomLevel) {
    // Pour compenser le zoom, on multiplie l'épaisseur par le facteur inverse
    // Zoom initial = 4.0 → on veut 1 pixel → thickness = 1
    // Zoom = 1.0 (4x moins zoomé) → on veut 4 pixels → thickness = 4
    // Zoom = 0.5 (8x moins zoomé) → on veut 8 pixels → thickness = 8

    float screenThickness = 1.0f; // Épaisseur désirée à l'écran en pixels
    float thickness = screenThickness * (3.0f / zoomLevel);

    std::cout << "Thickness: " << thickness << std::endl;

    int index = 0;

    // Lignes verticales
    for (int x = 0; x <= grid.cols; ++x) {
        if (index >= gridLines.size()) break;
        float px = x * CELL_SIZE;
        gridLines[index].setSize(sf::Vector2f(thickness, static_cast<float>(grid.rows * CELL_SIZE)));
        gridLines[index].setFillColor(sf::Color(150, 150, 150));
        gridLines[index].setPosition(sf::Vector2f(px - thickness / 2.0f, 0.f));
        index++;
    }

    // Lignes horizontales
    for (int y = 0; y <= grid.rows; ++y) {
        if (index >= gridLines.size()) break;
        float py = y * CELL_SIZE;
        gridLines[index].setFillColor(sf::Color(150, 150, 150));
        gridLines[index].setSize(sf::Vector2f(static_cast<float>(grid.cols * CELL_SIZE), thickness));
        gridLines[index].setPosition(sf::Vector2f(0.f, py - thickness / 2.0f));
        index++;
    }
}

GridGenerate::GridGenerate() {}