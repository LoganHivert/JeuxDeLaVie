#include "View.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "grid.h"
#include "Cells.h"

View::View() {
    viewWidth = static_cast<float>(COLS) * static_cast<float>(CELL_SIZE);
    viewHeight = static_cast<float>(ROWS) * static_cast<float>(CELL_SIZE);
}


void View::initialisation(sf::RenderWindow& window, sf::View& view,float initialScale){

	view.setCenter(sf::Vector2f(viewWidth / 2.f, viewHeight / 2.f)); // Centre de la vue au milieu de la grille

    view.setSize(sf::Vector2f(viewWidth / initialScale, viewHeight / initialScale));

    window.setView(view);
}


void View::ZoomView(std::optional<sf::Event>& event, sf::RenderWindow& window, sf::View& view) {

    if (auto wheel = event->getIf<sf::Event::MouseWheelScrolled>()) {
		sf::Vector2f size = view.getSize(); // taille actuelle de la vue

		if (wheel->delta > 0) {// Zoom avant
			if (size.x > MinZoom) view.zoom(0.9f);// agrandi la vue
        }
		else {// Zoom arrière
			if (size.x < MaxZoom) view.zoom(1.1f);// reduit la vue
        }
        window.setView(view);
    }
}
