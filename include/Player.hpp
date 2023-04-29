#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player();
        ~Player() {};

        void            setPosition(sf::Vector2f /*new position*/);
        sf::Vector2f    getSize();

        void            drawPlayer(sf::RenderWindow& /*main window*/);

    private:
        sf::Sprite          _playerSprite;
        sf::RectangleShape  _dummyRect;
};