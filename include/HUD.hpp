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
        void setMissedDelivery(unsigned int /*missed delivery*/);

    private:
        void loadFonts();
        FontHolder      _fontHolder;
        sf::Text        _scoreText;
        sf::Text        _deliveryFailed;
};

#endif // HUD_HPP