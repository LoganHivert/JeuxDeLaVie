#include "UI.h"
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "grid.h"

void UI::Windows() {

    Grid grid(CELL_SIZE, 60, 30);

    sf::RenderWindow window(sf::VideoMode({ static_cast<unsigned int>(grid.WindowsLength),static_cast<unsigned int>(grid.WindowsWidth) }), "Game of the life");
    // Conteneur pour stocker les rectangles de la grille
    std::vector<sf::RectangleShape> gridLines;
    // Lignes verticales
    for (int x = 0; x <= grid.rows; ++x) {
        float px = x * grid.cellSize;
        sf::RectangleShape line(sf::Vector2f(1, grid.WindowsWidth));
        line.setPosition(sf::Vector2f(px, 0));
        line.setFillColor(sf::Color(80, 80, 80));
        gridLines.push_back(line);
    }
    // Lignes horizontales
    for (int y = 0; y <= grid.cols; ++y) {
        float py = y * grid.cellSize;
        sf::RectangleShape line(sf::Vector2f(grid.WindowsLength, 1));
        line.setPosition(sf::Vector2f(0, py));
        line.setFillColor(sf::Color(80, 80, 80));
        gridLines.push_back(line);
    }

    while (window.isOpen()) { //laisse la fenetre ouverte 
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::Black);
        // Dessiner toutes les lignes
        for (auto& line : gridLines) {
            window.draw(line);
        }
        window.display();
    }
}