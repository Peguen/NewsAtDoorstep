#ifndef GAME_OVER_SCREEN_HPP
#define GAME_OVER_SCREEN_HPP

#include "Definitions.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

class GameOverScreen
{
    public:
        GameOverScreen();
        ~GameOverScreen(){};
        void init(FontHolder& /*gamefontholder*/, sf::Vector2u /*window size*/);

        void    setFinalScore(std::string /*final score*/);
        void    drawGameOverScreen(sf::RenderWindow& /*render window*/);

    public:
        sf::Text    _finalScore;
        FontHolder* _fontHolder;
};

#endif // GAME_OVER_SCREEN_HPP