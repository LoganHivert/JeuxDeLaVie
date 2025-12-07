#include "UI.h"
#include "Constantes.h"


UI::UI() {}

int UI::getPosXUi() {
    return (cell->getPosX() * CELL_SIZE);
}

int UI::getPosYUi() {
    return (cell->getPosY() * CELL_SIZE);
}

void UI::initializeWindow() {
    window.create(sf::VideoMode({ 1000u, 1000u }), "Game of Life");

    Zoom.initialisation(window, 4.f);
    gridLines = gridGenerate.createGridLines(grid);
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            cell = &grid.cells[y][x];
            cell->shape.setPosition(sf::Vector2f(static_cast<float>(getPosXUi()), static_cast<float>(getPosYUi())));
            cell->shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cell->shape.setFillColor(cell->alive ? sf::Color::White : sf::Color::Black);
            
        }
    }
}

void UI::handleCellClick(Grid* grid, sf::RenderWindow& window, const sf::Event::MouseButtonPressed& mouse) {
    sf::Vector2f worldPos = window.mapPixelToCoords(
        sf::Vector2i(mouse.position.x, mouse.position.y)
    );

    // Calculer quelle cellule a été cliquée
    int x = static_cast<int>(worldPos.x / CELL_SIZE);
    int y = static_cast<int>(worldPos.y / CELL_SIZE);

    // Vérifier que les coordonnées sont valides
    if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
        Cell& cell = grid->cells[y][x];
        if (cell.alive == 0) {
            cell.alive = 1;
        }
        else {
            cell.alive = 0;
        }
        cell.shape.setFillColor(cell.alive!=0 ? sf::Color::White : sf::Color::Black);
    }
}

void UI::displayWindow(sf::RenderWindow& window, Grid* grid) {
    window.clear(sf::Color::Black);

    //NON dans GridRenderer

    // Dessiner les lignes de la grille
    for (auto& line : gridLines) {
        window.draw(line);
    }

    // Dessiner toutes les cellules
    for (auto& row : grid->cells) {
        for (auto& cell : row) {
            window.draw(cell.shape);
        }
    }

    this->monBouton->draw(window);

    window.display();
}