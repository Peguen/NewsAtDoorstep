#include "Player.hpp"

Player::Player()
{
    _dummyRect.setSize(sf::Vector2f(100,100));
    _dummyRect.setOrigin(sf::Vector2f(50,0));
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

void Player::move(sf::Vector2f dirVec)
{
    _dummyRect.move(PLAYER_SPEED * dirVec.x, PLAYER_SPEED * dirVec.y);
}

sf::Vector2f Player::getSize()
{
    return _dummyRect.getSize();
}

sf::Vector2f Player::getPosition()
{
    return _dummyRect.getPosition();
}