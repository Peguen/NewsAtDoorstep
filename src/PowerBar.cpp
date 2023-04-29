#define _USE_MATH_DEFINES

#include "PowerBar.hpp"
#include <math.h>

PowerBar::PowerBar()
{
    _bar.setOutlineColor(sf::Color::Cyan);
    _bar.setOutlineThickness(BAR_OUTLINE_WIDTH);

    _bar.setOrigin(sf::Vector2f(BAR_WIDTH/2, 0));
}

void PowerBar::setStartPoint(sf::Vector2f newStartPoint)
{
    _bar.setPosition(newStartPoint);
}

void PowerBar::setEndPoint(sf::Vector2f newEndPoint)
{
    // calculate the bar length
    auto vecDif = newEndPoint - _bar.getPosition();
    _barLength = std::sqrt(vecDif.x * vecDif.x + vecDif.y * vecDif.y);
    _bar.setSize(sf::Vector2f(BAR_WIDTH, _barLength));
    
    // calculate the bar rotation
    //          A
    //          |
    //  lengthA |
    //          |
    //          ----------- B
    //            lengthB
    auto lengthA = newEndPoint.y - _bar.getPosition().y;
    auto lengthB = newEndPoint.x - _bar.getPosition().x;
    auto arc = std::atan(lengthB / lengthA);
    _barRotationAngle = -arc * 180/M_PI;
    
    // add 180 in case B is above A
    if (newEndPoint.y < _bar.getPosition().y)
        _barRotationAngle += 180;
    
    _bar.setRotation(_barRotationAngle);
}

float PowerBar::getLength()
{
    return _barLength;
}

float PowerBar::getBarRotationAngle()
{
    return _barRotationAngle;
}

void PowerBar::drawPowerBar(sf::RenderWindow& window)
{
    window.draw(_bar);
}