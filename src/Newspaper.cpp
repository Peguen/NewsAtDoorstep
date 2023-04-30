#include "Newspaper.hpp"

Newspaper::Newspaper()
: _velocity(START_VELOCITY)
{
    _newspaper.setSize(sf::Vector2f(100,30));
    _newspaper.setOrigin(sf::Vector2f(0,15));
    _newspaper.setFillColor(sf::Color::Blue);
}

void Newspaper::startFlying(sf::Vector2f startPosition, sf::Vector2f dirVec , float angle)
{
    _newspaper.setPosition(startPosition);
    _newspaper.setRotation(angle - 90);
    _directionVector = -dirVec;
}

void Newspaper::move(sf::Time elapsedTime)
{
    if (_velocity > 0)
    {
        _newspaper.move(_velocity * elapsedTime.asSeconds() * _directionVector.x, _velocity * elapsedTime.asSeconds() * _directionVector.y);
        _velocity -= VELOCITY_DEGRADATION;
    }
}

bool Newspaper::isFlying()
{
    return _velocity <= 0;
}

void Newspaper::drawNewspaper(sf::RenderWindow& window)
{
    _newspaper.move(sf::Vector2f(0, SCROLLING_SPEED));
    window.draw(_newspaper);
}

sf::Vector2f Newspaper::getPosition()
{
    return _newspaper.getPosition();
}