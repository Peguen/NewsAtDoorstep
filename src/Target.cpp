#include "Target.hpp"

Target::Target()
: _gotDelivered(false)
{
    _target.setSize(sf::Vector2f(20, 100));
    _house.setSize(sf::Vector2f(128, 128)); 
}

void Target::spawn(sf::Vector2f spawnPos, bool left, const sf::Texture& texture)
{
    _isLeft = left;

    _house.setTexture(&texture);
    _house.setScale(2, 2);
    _target.setPosition(spawnPos);
    _target.setScale(2, 2);
}

void Target::drawTarget(sf::RenderWindow& window)
{
    _target.move(sf::Vector2f(0, SCROLLING_SPEED));

    calculateHousePosition();
    
    window.draw(_house);
    // for debug purposes
    // window.draw(_target);
}

void Target::calculateHousePosition()
{   
    sf::Vector2f newPos;
    auto targetPos = _target.getPosition();

    if(_isLeft)
    {
        newPos.x = targetPos.x - 200;
        newPos.y = targetPos.y - 20;
    }
    else{
        newPos.x = targetPos.x - 20;
        newPos.y = targetPos.y - 20;
    }
    _house.setPosition(newPos);
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