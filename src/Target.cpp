#include "Target.hpp"

Target::Target()
{
    _circle.setFillColor(sf::Color::Green);
    _circle.setRadius(50);
}

void Target::spawn(sf::Vector2f spawnPos)
{
    _circle.setPosition(spawnPos);
}

void Target::drawTarget(sf::RenderWindow& window)
{
    _circle.move(sf::Vector2f(0, SCROLLING_SPEED));
    window.draw(_circle);
}

sf::Vector2f Target::getPosition()
{
    return _circle.getPosition();
}