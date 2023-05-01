#include "Player.hpp"

Player::Player()
: _timeSinceLastAnimationStep(0)
, _animationStep(0)
{
    _dummyRect.setSize(sf::Vector2f(64,64));
    _dummyRect.setOrigin(sf::Vector2f(50,0));

}

void Player::setTexture(const sf::Texture* texture)
{
    _dummyRect.setTexture(texture);
    _dummyRect.setTextureRect(sf::IntRect(0,0,64,64));
    _dummyRect.setScale(2,2);
}

void Player::drawPlayer(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(_dummyRect);
}

void Player::setPosition(sf::Vector2f newPosition)
{
    _dummyRect.setPosition(newPosition);
}

void Player::animate(sf::Time elapsedTime)
{
    if (150 <= _timeSinceLastAnimationStep)
    {
        _timeSinceLastAnimationStep = 0;
        _dummyRect.setTextureRect(sf::IntRect(64*(++_animationStep%4),0,64,64));
    }
    else
    {
        _timeSinceLastAnimationStep += elapsedTime.asMilliseconds();
    }
    
}

sf::Vector2f Player::getSize()
{
    return _dummyRect.getSize();
}

sf::Vector2f Player::getPosition()
{
    return _dummyRect.getPosition();
}

void Player::reset()
{
    _timeSinceLastAnimationStep = 0;
    _animationStep = 0;
}