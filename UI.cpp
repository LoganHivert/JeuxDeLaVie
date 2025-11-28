#include "UI.h"
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "grid.h"

// Fonction utilitaire pour générer les lignes de la grille
std::vector<sf::RectangleShape> createGridLines(const Grid& grid) {
    std::vector<sf::RectangleShape> gridLines;

    // Lignes verticales
    for (int x = 0; x <= grid.cols; ++x) {
        float px = x * CELL_SIZE;
        sf::RectangleShape line(sf::Vector2f(1.f, static_cast<float>(grid.WindowsLength)));
        line.setPosition(sf::Vector2f(px, 0.f));
        line.setFillColor(sf::Color(150, 150, 150));
        gridLines.push_back(line);
    }

    // Lignes horizontales
    for (int y = 0; y <= grid.rows; ++y) {
        float py = y * CELL_SIZE;
        sf::RectangleShape line(sf::Vector2f(static_cast<float>(grid.WindowsWidth), 1.f));
        line.setPosition(sf::Vector2f(0.f, py));
        line.setFillColor(sf::Color(150, 150, 150));
        gridLines.push_back(line);
    }

    return gridLines;
}

void UI::Windows() {
    // Initialisation de la grille
    Grid grid(100, 100);

    // Création de la fenêtre SFML
    sf::RenderWindow window(
        sf::VideoMode({
            static_cast<unsigned int>(800),
            static_cast<unsigned int>(800)
            }),
        "Game of Life"
    );

        float viewWidth = static_cast<float>(grid.cols) * static_cast<float>(CELL_SIZE);
    float viewHeight = static_cast<float>(grid.rows) * static_cast<float>(CELL_SIZE);

  
    sf::View view;
	view.setCenter(sf::Vector2f(viewWidth / 2.f, viewHeight / 2.f)); //centrer la vue
    view.setSize(sf::Vector2f(viewWidth, viewHeight));
    window.setView(view);

    // Génération des lignes de la grille
    std::vector<sf::RectangleShape> gridLines = createGridLines(grid);

	// Boucle windows principale
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
                int x = static_cast<int>(worldPos.x / CELL_SIZE);
                int y = static_cast<int>(worldPos.y / CELL_SIZE);

                // Vérifier que les coordonnées sont valides
                if (x >= 0 && x < grid.cols && y >= 0 && y < grid.rows) {
                    int index = y * grid.cols + x;
                    if (grid.cellGraph[index].getFillColor() == sf::Color::Black)
                        grid.cellGraph[index].setFillColor(sf::Color::White); // vivante
                    else
                        grid.cellGraph[index].setFillColor(sf::Color::Black); // morte
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
        for (auto& shape : grid.cellGraph) {
            window.draw(shape);
        }

        // Dessiner les lignes de la grille
        for (auto& line : gridLines) {
            window.draw(line);
        }

        window.display();
    }
}