#ifndef HUD_HPP
#define HUD_HPP

#include <vector>

#include "Definitions.hpp"
#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

class HUD
{
    public:
        HUD(sf::Vector2u /*window size*/);
        ~HUD(){};

        void drawHUD(sf::RenderWindow& /*window to render*/);
        void setScore(unsigned int /*score string*/);
        void setMissedDelivery(unsigned int /*missed delivery*/);

        void prepareGameOver();
        void drawGameOverScreen(sf::RenderWindow& /*window to render*/);

        void drawPauseScreen(sf::RenderWindow& /*window to render*/);

    private:
        void loadFonts();
        sf::Vector2u    _windowSize;
        FontHolder      _fontHolder;
        sf::Text        _scoreText;
        sf::Text        _deliveryFailed;
        unsigned int    _score;
        
        // GamoverScreen
        void setText(sf::Text& /*text to set*/);
        sf::Text            _highscore;
        sf::Text            _newRecord;
        std::vector<int>    _highscoreList;
        bool                _isNewRecord;

        void setupHowToPlay();
        sf::Text            _howToPlay;
};

#endif // HUD_HPP