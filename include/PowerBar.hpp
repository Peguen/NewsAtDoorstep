#ifndef POWERBAR_HPP
#define POWERBAR_HPP

#include "Definitions.hpp"
class PowerBar
{
    public:
        PowerBar();
        ~PowerBar() {};

        void            setStartPoint(sf::Vector2f /*starting point of bar*/);
        void            setEndPoint(sf::Vector2f /*end point of bar*/);
        float           getLength();
        float           getBarRotationAngle();
        sf::Vector2f    getBarDirectionVector();

        void            drawPowerBar(sf::RenderWindow& /*main window*/);

        private:
            sf::RectangleShape  _bar;
            float               _barLength;
            float               _barRotationAngle;
            sf::Vector2f        _barDirVec;
};

#endif // POWERBAR_HPP