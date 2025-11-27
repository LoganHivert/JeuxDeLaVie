#include "UI.h"
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "grid.h"

void UI::Windows() {
    // Récupérer la taille de l'écran
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    // Calculer combien de cellules rentrent à l'écran
    int rows = desktop.size.x / CELL_SIZE;
    int cols = desktop.size.y / CELL_SIZE;

    Grid grid(CELL_SIZE, rows, cols);

    // Créer fenêtre en plein écran
    sf::RenderWindow window(desktop, "Game of the life", sf::State::Windowed);

    // Conteneur pour stocker les rectangles de la grille
    std::vector<sf::RectangleShape> gridLines;

    // Lignes verticales
    for (int x = 0; x <= grid.rows; ++x) {
        float px = x * grid.cellSize;
        sf::RectangleShape line(sf::Vector2f(1.f, static_cast<float>(grid.WindowsWidth)));
        line.setPosition(sf::Vector2f(px, 0.f));
        line.setFillColor(sf::Color(80, 80, 80));
        gridLines.push_back(line);
    }

    // Lignes horizontales
    for (int y = 0; y <= grid.cols; ++y) {
        float py = y * grid.cellSize;
        sf::RectangleShape line(sf::Vector2f(static_cast<float>(grid.WindowsLength), 1.f));
        line.setPosition(sf::Vector2f(0.f, py));
        line.setFillColor(sf::Color(80, 80, 80));
        gridLines.push_back(line);
    }

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
            // Échap pour quitter le plein écran
            if (event->is<sf::Event::KeyPressed>()) {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape)
                    window.close();
            }
        }

        window.clear(sf::Color::Black);

        // Dessiner toutes les lignes
        for (auto& line : gridLines) {
            window.draw(line);
        }

        window.display();
    }
}