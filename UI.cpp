#include "UI.h"
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "grid.h"

// Fonction utilitaire pour générer les lignes de la grille
std::vector<sf::RectangleShape> createGridLines(const Grid& grid) {
    std::vector<sf::RectangleShape> gridLines;

    // Lignes verticales
    for (int x = 0; x <= grid.cols; ++x) {
        float px = x * grid.cellSize;
        sf::RectangleShape line(sf::Vector2f(1.f, static_cast<float>(grid.WindowsLength)));
        line.setPosition(sf::Vector2f(px, 0.f));
        line.setFillColor(sf::Color(150, 150, 150));
        gridLines.push_back(line);
    }

    // Lignes horizontales
    for (int y = 0; y <= grid.rows; ++y) {
        float py = y * grid.cellSize;
        sf::RectangleShape line(sf::Vector2f(static_cast<float>(grid.WindowsWidth), 1.f));
        line.setPosition(sf::Vector2f(0.f, py));
        line.setFillColor(sf::Color(150, 150, 150));
        gridLines.push_back(line);
    }

    return gridLines;
}

void UI::Windows() {
    // Initialisation de la grille
    Grid grid(CELL_SIZE, 100, 100);

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    // Création de la fenêtre SFML
    sf::RenderWindow window(
        sf::VideoMode({
            static_cast<unsigned int>(desktop.size.x *0.8f),
            static_cast<unsigned int>(desktop.size.y*0.7f)
            }),
        "Game of Life"
    );

        float viewWidth = static_cast<float>(grid.cols) * static_cast<float>(grid.cellSize);
    float viewHeight = static_cast<float>(grid.rows) * static_cast<float>(grid.cellSize);

    // SFML 3.0.2 : utilise setCenter et setSize au lieu de reset
    sf::View view;
    view.setCenter(sf::Vector2f(viewWidth / 2.f, viewHeight / 2.f));
    view.setSize(sf::Vector2f(viewWidth, viewHeight));
    window.setView(view);

    // Génération des lignes de la grille
    std::vector<sf::RectangleShape> gridLines = createGridLines(grid);

    // Création des cellules
    std::vector<sf::RectangleShape> cells;
    cells.reserve(grid.rows * grid.cols);
    for (int y = 0; y < grid.rows; ++y) {
        for (int x = 0; x < grid.cols; ++x) {
            sf::RectangleShape cell(sf::Vector2f(grid.cellSize, grid.cellSize));
            cell.setPosition(sf::Vector2f(x * grid.cellSize, y * grid.cellSize));
            cell.setFillColor(sf::Color::Black); // cellule morte
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color(150, 150, 150));
            cells.push_back(cell);
        }
    }

    // Boucle principale
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Clic souris : basculer l'état d'une cellule
            if (auto mouse = event->getIf<sf::Event::MouseButtonPressed>()) {
                // CORRECTION : Convertir les coordonnées écran en coordonnées monde
                sf::Vector2f worldPos = window.mapPixelToCoords(
                    sf::Vector2i(mouse->position.x, mouse->position.y)
                );

                // Calculer quelle cellule a été cliquée
                int x = static_cast<int>(worldPos.x / grid.cellSize);
                int y = static_cast<int>(worldPos.y / grid.cellSize);

                // Vérifier que les coordonnées sont valides
                if (x >= 0 && x < grid.cols && y >= 0 && y < grid.rows) {
                    int index = y * grid.cols + x;
                    if (cells[index].getFillColor() == sf::Color::Black)
                        cells[index].setFillColor(sf::Color::White); // vivante
                    else
                        cells[index].setFillColor(sf::Color::Black); // morte
                }
            }

            // Zoom avec la molette
            if (auto wheel = event->getIf<sf::Event::MouseWheelScrolled>()) {
 

                // Récupérer la taille actuelle de la vue
                sf::Vector2f size = view.getSize();

                if (wheel->delta > 0) {
                    // Zoom avant
                    if (size.x > MinZoom) {
                        view.zoom(0.9f);
                    }
                }
                else {
                    // Zoom arrière
                    if (size.x < MaxZoom) {
                        view.zoom(1.1f);
                    }
                }

                window.setView(view);
            }
        }

        window.clear(sf::Color::Black);

        // Dessiner toutes les cellules
        for (auto& cell : cells) {
            window.draw(cell);
        }

        // Dessiner les lignes de la grille
        for (auto& line : gridLines) {
            window.draw(line);
        }

        window.display();
    }
}