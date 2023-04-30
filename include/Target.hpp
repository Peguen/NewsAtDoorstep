#ifndef TARGET_HPP
#define TARGET_HPP

#include "Definitions.hpp"

class Target
{
    public:
        Target();
        ~Target() {};

        void spawn(sf::Vector2f /*spawn position*/);
        
        void            drawTarget(sf::RenderWindow& /*target window*/);
        sf::Vector2f    getPosition();

    private:
        sf::CircleShape  _circle;
};

#endif // TARGET_HPP