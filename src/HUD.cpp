#include "HUD.hpp"

HUD::HUD(sf::Vector2u windowSize)
{
    loadFonts();

    _scoreText.setFont(_fontHolder.get(Fonts::Main));
    _scoreText.setPosition(windowSize.x/2 - 100, 10.f);
    _scoreText.setCharacterSize(50u);
    _scoreText.setFillColor(sf::Color::White);
}

void HUD::loadFonts()
{
    _fontHolder.load(Fonts::Main, "./resources/fonts/Raleway-ExtraBold.ttf");
}

void HUD::setScore(std::string score)
{
    _scoreText.setString("Score: " + score);
}

void HUD::drawHUD(sf::RenderWindow& window)
{
    window.draw(_scoreText);
}

