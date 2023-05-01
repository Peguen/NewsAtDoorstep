#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Definitions.hpp"

class Player
{
    public:
        Player();
        ~Player() {};

        void                setPosition(sf::Vector2f /*new position*/);
        void                setTexture(const sf::Texture* /*reference to texture*/);
        sf::Vector2f        getSize();
        sf::Vector2f        getPosition();
        void                animate(sf::Time /*direction vector*/);
        void                reset();

        void                drawPlayer(sf::RenderWindow& /*main window*/);

    private:
        sf::Sprite          _playerSprite;
        sf::RectangleShape  _dummyRect;
        unsigned int        _timeSinceLastAnimationStep;
        unsigned int        _animationStep;
};

#endif // PLAYER_HPP