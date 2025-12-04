#include "UI.h"
#include "Cells.h"
#include <SFML/Graphics.hpp>
#include "grid.h"
#include "GridGenerate.h"
#include "View.h"
#include "Bouton.h"

UI::UI() : Game(nullptr) {}

void UI::Windows(Grid* grid) {
    GridGenerate gridGenerate;
    // Création de la fenêtre SFML
    sf::RenderWindow window(
        sf::VideoMode({1000u, 1000u}),
        "Game of Life"
    );

    sf::Font font; 

    Button monBouton(300, 250, 200, 100, font, "Cliquez ici!");

  
    sf::View view;
    View Zoom;
    
    Zoom.initialisation(window, view, 4.f); //fenetre zoomer

    // Génération des lignes de la grille
    std::vector<sf::RectangleShape> gridLines = gridGenerate.createGridLines(*grid);

	// Boucle windows principale
    while (window.isOpen()) {
        std::optional<sf::Event> event;
        while ((event = window.pollEvent()).has_value()) {
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
                if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
                    Cell& cell = grid->cells[y][x]; // accès direct à la cellule
                    if (!cell.alive) {
                        cell.shape.setFillColor(sf::Color::White); // vivante
                        cell.alive = true;
                    }
                    else {
                        cell.shape.setFillColor(sf::Color::Black); // morte
                        cell.alive = false;
                    }
                }
            }

            Zoom.ZoomView(event, window, view); // Gestion du zoom
        }

        window.clear(sf::Color::Black);

        // Dessiner toutes les cellules
        for (auto& row : grid->cells) {
            for (auto& cell : row) {
                window.draw(cell.shape);
            }
        }

        // Dessiner les lignes de la grille
        for (auto& line : gridLines) {
            window.draw(line);
        }

        window.display();
    }
}

void UI::gameRun(){
    Windows(grid);
}