#pragma once
#include <SFML/Graphics.hpp>

class View {
public:
    const float MinZoom = 400.f;
    const float MaxZoom = 3000.f;
    float viewWidth;
    float viewHeight;
    View();
    void initialisation(sf::RenderWindow& window, sf::View& view, float initialScale);
    void ZoomView(std::optional<sf::Event>& event, sf::RenderWindow& window, sf::View& view);
};


