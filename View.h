#pragma once
#include <SFML/Graphics.hpp>

class View {
public:
    const float MinZoom = 400.f;
    const float MaxZoom = 3000.f;
    float viewWidth;
    float viewHeight;
    View();
    sf::View view;
    void zoomIn(sf::RenderWindow& window);
    void zoomOut(sf::RenderWindow& window);
    void initialisation(sf::RenderWindow& window, float initialScale);
    //void ZoomView(std::optional<sf::Event>& event, sf::RenderWindow& window, sf::View& view);
};


