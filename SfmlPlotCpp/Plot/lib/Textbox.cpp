#include "../include/Textbox.hpp"

Textbox::Textbox(float xStart, float yStart, float width, float height, sf::Font& font) {
    h = height;
    w = width;

    x = xStart;
    y = yStart;

    box.setPosition(sf::Vector2f(x, y));
    box.setSize(sf::Vector2f(w, h));
    box.setOutlineThickness(1);
    box.setFillColor(sf::Color::Black);
    box.setOutlineColor(sf::Color::White);

    text.setFont(font);
    text.setCharacterSize(height);
    text.setPosition(sf::Vector2f(x, y));

    text.setString("");
}

void Textbox::setText(std::string txt) {
    text.setString(txt);

}

sf::Vector2f Textbox::getCoord() {
    return {x, y};
}

dim Textbox::getDim() {
    return { w, h };
}

bool Textbox::contains(sf::Vector2i coord) {
    if (coord.x > x && coord.x < x + w &&
        coord.y > y && coord.y < y + h)
        return true;
    
    return false;
}

void Textbox::setSize(float width, float height) {
    
    w = width;
    h = height;

    box.setSize(sf::Vector2f(w, h));

    text.setCharacterSize(height - 0.05);
}

void Textbox::setPosition(float xStart, float yStart) {

    x = xStart;
    y = yStart;

    box.setPosition(sf::Vector2f(x, y));
    text.setPosition(sf::Vector2f(x, y));

}