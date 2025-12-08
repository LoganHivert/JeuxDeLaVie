#include "View.h"
#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Cells.h"
#include "Constantes.h"
#include "UIRun.h"

View::View(Grid* grid) {
    viewWidth = static_cast<float>(grid->cols) * static_cast<float>(CELL_SIZE);
    viewHeight = static_cast<float>(grid->rows) * static_cast<float>(CELL_SIZE);
}

void View::initialisation(sf::RenderWindow& window,float initialScale){

	view.setCenter(sf::Vector2f(viewWidth / 2.f, viewHeight / 2.f)); // Centre de la vue au milieu de la grille

    view.setSize(sf::Vector2f(viewWidth / initialScale, viewHeight / initialScale));
    currentZoomLevel = initialScale;

    window.setView(view);
}

void View::zoomIn(sf::RenderWindow& window) {
    sf::Vector2f size = view.getSize(); // taille actuelle de la vue
    UI ui;
    if (size.x > MinZoom) {
        view.zoom(0.9f);// agrandi la vue
        currentZoomLevel /= 0.9f; // Inverse car zoom() réduit la vue
        window.setView(view);
    }
}


void View::zoomOut(sf::RenderWindow& window){
    sf::Vector2f size = view.getSize(); // taille actuelle de la vue
    if (size.x < MaxZoom) {
        view.zoom(1.1f);// retrecir la vue
        currentZoomLevel /= 1.1f;
        window.setView(view);
    }
}
