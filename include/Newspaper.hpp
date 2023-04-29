#ifndef NEWSPAPER_HPP
#define NEWSPAPER_HPP

#include "Definitions.hpp"

class Newspaper
{
    public:
        Newspaper();
        ~Newspaper() {};

        void                drawNewspaper(sf::RenderWindow& /*target window*/);
        void                startFlying(sf::Vector2f /*start position*/, sf::Vector2f /*direction vector*/, float /*angle*/, sf::Vector2u /*window size*/);
        void                move(sf::Time /*elapsed time*/);

        bool                removePaper();

    private:
        sf::RectangleShape  _newspaper;
        sf::Vector2f        _directionVector;
        sf::Vector2u        _windowSize;
        float               _velocity{START_VELOCITY};
};

#endif // NEWSPAPER_HPP