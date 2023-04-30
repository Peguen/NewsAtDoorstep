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
        bool                isFlying();

    private:
        sf::RectangleShape  _newspaper;
        sf::Vector2f        _directionVector;
        float               _velocity;
};

#endif // NEWSPAPER_HPP