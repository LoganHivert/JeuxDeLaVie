#pragma once
#include <SFML/Graphics.hpp>
#include "grid.h"

class View {
public:
    const float MinZoom = 400.f;
    const float MaxZoom = 4000.f;
    float currentZoomLevel = 1.0f; // Niveau de zoom actuel
    float viewWidth;
    float viewHeight;
    View(Grid* grid);
    sf::View view;
    void zoomIn(sf::RenderWindow& window);
    void zoomOut(sf::RenderWindow& window);
    void initialisation(sf::RenderWindow& window, float initialScale);
    float getZoomLevel() const { return currentZoomLevel; }
    //void ZoomView(std::optional<sf::Event>& event, sf::RenderWindow& window, sf::View& view);
};
