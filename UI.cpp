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
    std::cout << "Fenêtre créée : " << window.getSize().x << "x" << window.getSize().y << std::endl;
    Zoom.initialisation(window, 4.f);
    sf::View v = window.getView();
    std::cout << "Vue après init : size=" << v.getSize().x << "x" << v.getSize().y << std::endl;
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
    std::cout << "=== CLIC DÉTECTÉ ===" << std::endl;
    std::cout << "Position souris: (" << mouse.position.x << ", " << mouse.position.y << ")" << std::endl;

    // ? SOLUTION : Utilise directement les coordonnées pixel
    // Récupère la position de la vue
    sf::Vector2u windowSize = window.getSize();
    sf::View currentView = window.getView();
    sf::Vector2f viewSize = currentView.getSize();
    sf::Vector2f viewCenter = currentView.getCenter();

    std::cout << "Taille fenêtre: (" << windowSize.x << ", " << windowSize.y << ")" << std::endl;
    std::cout << "Taille vue: (" << viewSize.x << ", " << viewSize.y << ")" << std::endl;
    std::cout << "Centre vue: (" << viewCenter.x << ", " << viewCenter.y << ")" << std::endl;

    if (windowSize.x == 0 || windowSize.y == 0) {
        std::cerr << "? FENÊTRE INVALIDE !" << std::endl;
        return;
    }

    // Calcule les coordonnées monde manuellement
    float worldX = viewCenter.x - viewSize.x / 2.0f + (mouse.position.x * viewSize.x / windowSize.x);
    float worldY = viewCenter.y - viewSize.y / 2.0f + (mouse.position.y * viewSize.y / windowSize.y);

    std::cout << "Position monde calculée: (" << worldX << ", " << worldY << ")" << std::endl;

    int x = static_cast<int>(worldX / CELL_SIZE);
    int y = static_cast<int>(worldY / CELL_SIZE);

    std::cout << "Cellule cliquée: (" << x << ", " << y << ")" << std::endl;

    if (x >= 0 && x < COLS && y >= 0 && y < ROWS) {
        Cell& cell = grid->cells[y][x];
        cell.alive = (cell.alive == 0) ? 1 : 0;
        cell.shape.setFillColor(cell.alive != 0 ? sf::Color::White : sf::Color::Black);
        std::cout << "? Cellule modifiée !" << std::endl;
    }
    else {
        std::cout << "?? Clic hors limites" << std::endl;
    }
    std::cout << "===================" << std::endl;
}

void UI::displayWindow(Grid* grid) {  // Enlève le paramètre window
    if (grid == nullptr) {
        std::cerr << "ERREUR : grid est nullptr !" << std::endl;
        return;
    }

    window.clear(sf::Color::Black);  // Utilise directement this->window

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