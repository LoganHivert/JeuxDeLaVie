#include "Buttons.h"

Button::Button(float x, float y, float width, float height, sf::Font& font, const std::string& label)
    : text(font) {  // Initialiser text avec font directement

    // Configuration du rectangle
    shape.setPosition({ x, y });
    shape.setSize({ width, height });
    shape.setFillColor(sf::Color(238,130,238));

    // Configuration du texte
    text.setString(label);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);

    // Centrer le texte dans le bouton
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin({ textBounds.size.x / 2.f, textBounds.size.y / 2.f });
    text.setPosition({ x + width / 2.1f, y + height / 2.2f });
}

bool Button::isClicked(const sf::Event& event) {//TODO on devrait recevoir direct un vector2f
    if (const auto* mouse = event.getIf<sf::Event::MouseButtonPressed>()) {
        sf::Vector2f mousePos(
            static_cast<float>(mouse->position.x),
            static_cast<float>(mouse->position.y)
        );
        return shape.getGlobalBounds().contains(mousePos);
    }
    return false;
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}