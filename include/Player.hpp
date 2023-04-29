#include <SFML/Graphics.hpp>

#define PLAYER_SPEED 10
class Player
{
    public:
        Player();
        ~Player() {};

        void                setPosition(sf::Vector2f /*new position*/);
        sf::Vector2f        getSize();
        sf::Vector2f        getPosition();
        void                move(sf::Vector2f /*direction vector*/);

        void                drawPlayer(sf::RenderWindow& /*main window*/);

    private:
        sf::Sprite          _playerSprite;
        sf::RectangleShape  _dummyRect;
};