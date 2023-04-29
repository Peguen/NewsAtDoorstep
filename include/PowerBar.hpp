#include <SFML/Graphics.hpp>

#define BAR_WIDTH 20
#define BAR_OUTLINE_WIDTH 5

class PowerBar
{
    public:
        PowerBar();
        ~PowerBar() {};

        void    setStartPoint(sf::Vector2f /*starting point of bar*/);
        void    setEndPoint(sf::Vector2f /*end point of bar*/);
        float   getLength();
        float   getBarRotationAngle();

        void    drawPowerBar(sf::RenderWindow& /*main window*/);

        private:
            sf::RectangleShape  _bar;
            float               _barLength;
            float               _barRotationAngle;
};