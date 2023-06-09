#ifndef TARGET_HPP
#define TARGET_HPP

#include "Definitions.hpp"

class Target
{
    public:
        Target();
        ~Target() {};

        void spawn(sf::Vector2f /*spawn position*/, bool /*if left*/, const sf::Texture& texture);
        
        void            drawTarget(sf::RenderWindow& /*target window*/);
        sf::Vector2f    getPosition();
        sf::FloatRect   getGlobalBounds();
        void            setDelivered();
        bool            isDelivered();

    private:
        sf::RectangleShape  _target;
        sf::RectangleShape  _house;
        bool                _gotDelivered;

        bool                _isLeft;

        void calculateHousePosition();
};

#endif // TARGET_HPP