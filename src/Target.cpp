#include "Target.hpp"

Target::Target()
: _gotDelivered(false)
{
    _target.setFillColor(sf::Color::Green);
    _target.setSize(sf::Vector2f(100,100));
}

void Target::spawn(sf::Vector2f spawnPos)
{
    _target.setPosition(spawnPos);
}

void Target::drawTarget(sf::RenderWindow& window)
{
    _target.move(sf::Vector2f(0, SCROLLING_SPEED));
    window.draw(_target);
}

sf::Vector2f Target::getPosition()
{
    return _target.getPosition();
}

sf::FloatRect Target::getGlobalBounds()
{
    return _target.getGlobalBounds();
}

void Target::setDelivered()
{
    _gotDelivered = true;
}

bool Target::isDelivered()
{
    return _gotDelivered;
}