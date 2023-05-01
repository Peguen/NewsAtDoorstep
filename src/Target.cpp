#include "Target.hpp"

Target::Target()
: _gotDelivered(false)
{
    _target.setSize(sf::Vector2f(220, 110));
    _house.setSize(sf::Vector2f(461, 376)); 
}

void Target::spawn(sf::Vector2f spawnPos, bool left, const sf::Texture& texture)
{
    _isLeft = left;

    _house.setTexture(&texture);

    _target.setPosition(spawnPos);
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
        newPos.x = targetPos.x - 235;
        newPos.y = targetPos.y - 132;
    }
    else{
        newPos.x = targetPos.x - 13;
        newPos.y = targetPos.y - 132;
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