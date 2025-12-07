#include "UI.h"
#include "Constantes.h"


UI::UI() {}

void UI::CheckGridColor(Grid* grid) {
    for (int i = 0; i < grid->cols; i++) {
        for (int j = 0; j < grid->rows; j++) {
            if (grid->cells[i][j].alive) {
                grid->cells[i][j].shape.setFillColor(sf::Color::White);
            }
            else {
                grid->cells[i][j].shape.setFillColor(sf::Color::Black);
            }
        }
    }
}

int UI::getPosXUi() {
    return (cell->getPosX() * CELL_SIZE);
}

int UI::getPosYUi() {
    return (cell->getPosY() * CELL_SIZE);
}

void UI::initializeWindow(Grid* grid) {
    window.create(sf::VideoMode({ 1000u, 1000u }), "Game of Life");
    Zoom = new View(grid);
    Zoom->initialisation(window, 4.f);
    sf::View v = window.getView();
    gridLines = gridGenerate.createGridLines(*grid);
    for (int y = 0; y < grid->rows; y++) {
        for (int x = 0; x < grid->cols; x++) {
            cell = &grid->cells[y][x];
            cell->shape.setPosition(sf::Vector2f(static_cast<float>(getPosXUi()), static_cast<float>(getPosYUi())));
            cell->shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cell->shape.setFillColor(cell->alive ? sf::Color::White : sf::Color::Black);
            
        }
    }
}

void UI::handleCellClick(Grid* grid, sf::RenderWindow& window, const sf::Event::MouseButtonPressed& mouse) {
    sf::Vector2f worldPos = window.mapPixelToCoords(sf::Vector2i(mouse.position.x, mouse.position.y));

    int x = static_cast<int>(worldPos.x / CELL_SIZE);
    int y = static_cast<int>(worldPos.y / CELL_SIZE);

    if (x >= 0 && x < grid->cols && y >= 0 && y < grid->rows) {
        Cell& cell = grid->cells[y][x];
        cell.alive = (cell.alive == 0) ? 1 : 0;
        cell.shape.setFillColor(cell.alive != 0 ? sf::Color::White : sf::Color::Black);
    }
}

void UI::displayWindow(Grid* grid) {
    if (grid == nullptr) {
        return;
    }

    window.clear(sf::Color::Black);

    for (auto& line : gridLines) {
        window.draw(line);
    }
    for (auto& row : grid->cells) {
        for (auto& cell : row) {
            window.draw(cell.shape);
        }
    }
    if (this->monBouton != nullptr) {
        this->monBouton->draw(window);
    }
    window.display();
}