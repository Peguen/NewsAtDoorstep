#ifndef HUD_HPP
#define HUD_HPP

#include "Definitions.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

class HUD
{
    public:
        HUD(sf::Vector2u /*window size*/);
        ~HUD(){};

        void drawHUD(sf::RenderWindow& /*window to render*/);
        void setScore(std::string /*score string*/);

    private:
        void loadFonts();
        FontHolder      _fontHolder;
        sf::Text        _scoreText;
};

#endif // HUD_HPP