#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(float x, float y, float width, float height,
        sf::Font& font, const std::string& label);

    bool isClicked(const sf::Vector2f& mousePos);
    void draw(sf::RenderWindow& window);
};

