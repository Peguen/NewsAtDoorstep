#include <SFML/Graphics.hpp>

#define START_VELOCITY 3
#define VELOCITY_DEGRADATION 0.05f
class Newspaper
{
    public:
        Newspaper();
        ~Newspaper() {};

        void                drawNewspaper(sf::RenderWindow& /*target window*/);
        void                startFlying(sf::Vector2f /*start position*/, sf::Vector2f /*direction vector*/, float /*angle*/);
        void                move(sf::Time /*elapsed time*/);
    private:
        sf::RectangleShape  _newspaper;
        sf::Vector2f        _directionVector;
        float               _velocity{START_VELOCITY};
};