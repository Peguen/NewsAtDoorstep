#include "Player.hpp"

Player::Player()
{
    _dummyRect.setSize(sf::Vector2f(100,100));
    _dummyRect.setFillColor(sf::Color::White);
}

void Player::drawPlayer(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(_dummyRect);
}

void Player::setPosition(sf::Vector2f newPosition)
{
    _dummyRect.setPosition(newPosition);
}

sf::Vector2f Player::getSize()
{
    return _dummyRect.getSize();
}