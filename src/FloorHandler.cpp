#include "FloorHandler.hpp"

FloorHandler::FloorHandler()
{
    // hardcoded because time is running (not only the postman)
    _gras.setSize(sf::Vector2f(1920, 1112));
    _street.setSize(sf::Vector2f(300, 1130));

    _gras.setPosition(sf::Vector2f(0, -32));
    _street.setPosition(sf::Vector2f(810, -50));

    _gras.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    _street.setTextureRect(sf::IntRect(0,0,300, 1080));

    _grasTexture.loadFromFile("./resources/images/Gras.png");
    _grasTexture.setRepeated(true);

    _streetTexture.loadFromFile("./resources/images/Street.png");
    _streetTexture.setRepeated(true);

    _gras.setTexture(&_grasTexture);
    _street.setTexture(&_streetTexture);
}

void FloorHandler::drawFloor(sf::RenderWindow& window)
{
    if (_street.getPosition().y >= 0)
        _street.setPosition(sf::Vector2f(810, -50));
    
    _street.move(0, SCROLLING_SPEED);

    if (_gras.getPosition().y >= 0)
        _gras.setPosition(sf::Vector2f(0, -32));

    _gras.move(0, SCROLLING_SPEED);

    window.draw(_gras);
    window.draw(_street);
}


