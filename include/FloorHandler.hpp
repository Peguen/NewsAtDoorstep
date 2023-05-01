#ifndef FLOOR_HANDLER_HPP
#define FLOOR_HANDLER_HPP

#include "Definitions.hpp"

class FloorHandler
{
    public:
        FloorHandler();
        ~FloorHandler(){};

        void    drawFloor(sf::RenderWindow& /*window*/);
    
    private:
        sf::RectangleShape  _gras;
        sf::RectangleShape  _street;

        sf::Texture         _grasTexture;
        sf::Texture         _streetTexture;
        
};

#endif // FLOOR_HANDLER_HPP