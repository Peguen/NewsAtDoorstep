#ifndef HUD_HPP
#define HUD_HPP

#include "Definitions.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"
#include "GameOverScreen.hpp"

class HUD
{
    public:
        HUD(sf::Vector2u /*window size*/);
        ~HUD(){};

        void drawHUD(sf::RenderWindow& /*window to render*/);
        void setScore(std::string /*score string*/);
        void setMissedDelivery(unsigned int /*missed delivery*/);

        void drawGameOverScreen(sf::RenderWindow& /*window to render*/);

    private:
        void loadFonts();
        FontHolder      _fontHolder;
        sf::Text        _scoreText;
        sf::Text        _deliveryFailed;
        GameOverScreen  _gameOverScreen;
};

#endif // HUD_HPP