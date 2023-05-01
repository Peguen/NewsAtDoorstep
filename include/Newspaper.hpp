#ifndef NEWSPAPER_HPP
#define NEWSPAPER_HPP

#include "Definitions.hpp"

class Newspaper
{
    public:
        Newspaper();
        ~Newspaper() {};

        void                drawNewspaper(sf::RenderWindow& /*target window*/);
        void                startFlying(sf::Vector2f /*start position*/, sf::Vector2f /*direction vector*/, float /*angle*/);
        void                move(sf::Time /*elapsed time*/);

        sf::Vector2f        getPosition();
        bool                hasLanded();
        void                setLandedOnTarget(bool /*target landed indicator*/);
        bool                hasLandedOnTarget();
        bool                isMarkedForScore();
        bool                getScoreValue();
        void                setTexture(const sf::Texture& /*newspaper texture*/);

        sf::FloatRect       getGlobalBounds();

    private:
        sf::RectangleShape  _newspaper;
        sf::Vector2f        _directionVector;
        bool                _landedOnTarget;
        float               _velocity;
        float               _rotationSpeed;
        bool                _markForScoreCount;
};

#endif // NEWSPAPER_HPP