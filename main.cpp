#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "grid.h"

int main() {
    Grid grid(CELL_SIZE, 60, 30);
    sf::RenderWindow window(sf::VideoMode({ static_cast<unsigned int>(grid.WindowsLength),static_cast<unsigned int>(grid.WindowsWidth) }), "Game of the life");
    sf::VertexArray gridLines(sf::PrimitiveType::Lines);
    for (int x = 0; x <= grid.rows; ++x) {
        float px = x * grid.cellSize;
        gridLines.append(sf::Vertex(sf::Vector2f(px, 0), sf::Color(80, 80, 80)));
        gridLines.append(sf::Vertex(sf::Vector2f(px, grid.WindowsWidth), sf::Color(80, 80, 80)));
    }

    for (int y = 0; y <= grid.cols; ++y) {
        float py = y * grid.cellSize;
        gridLines.append(sf::Vertex(sf::Vector2f(0, py), sf::Color(80, 80, 80)));
        gridLines.append(sf::Vertex(sf::Vector2f(grid.WindowsLength, py), sf::Color(80, 80, 80)));
    }

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(gridLines);
        window.display();
    }
}