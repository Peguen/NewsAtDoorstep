#include "Newspaper.hpp"

Newspaper::Newspaper()
: _velocity(START_VELOCITY)
, _rotationSpeed(20)
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
    if (_velocity < 1)
        _rotationSpeed *= _velocity;

    if (_velocity > 0)
    {
        _newspaper.move(_velocity * elapsedTime.asSeconds() * _directionVector.x, _velocity * elapsedTime.asSeconds() * _directionVector.y);
        _newspaper.rotate(_rotationSpeed);
        _velocity -= VELOCITY_DEGRADATION;
    }
    else{
        // _newspaper.setRotation(0);
    }
}

bool Newspaper::hasLanded()
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

sf::FloatRect Newspaper::getGlobalBounds()
{
    return _newspaper.getGlobalBounds();
}

void Newspaper::setLandedOnTarget(bool landed)
{
    _landedOnTarget = landed;
    if (landed)
    {
        _newspaper.setFillColor(sf::Color::Green);
    }
    else
    {
        _newspaper.setFillColor(sf::Color::Red);
    }
}