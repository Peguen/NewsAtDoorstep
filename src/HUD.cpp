#include "HUD.hpp"

HUD::HUD(sf::Vector2u windowSize)
{
    loadFonts();

    _gameOverScreen.init(_fontHolder, windowSize);

    _scoreText.setFont(_fontHolder.get(Fonts::Main));
    _scoreText.setPosition(windowSize.x/2 - 100, 10.f);
    _scoreText.setCharacterSize(50u);
    _scoreText.setFillColor(sf::Color::White);

    _deliveryFailed.setFont(_fontHolder.get(Fonts::Main));
    _deliveryFailed.setPosition(windowSize.x/2 - 100, 70.f);
    _deliveryFailed.setCharacterSize(50u);
    _deliveryFailed.setFillColor(sf::Color::White);
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
    window.draw(_deliveryFailed);
}

void HUD::setMissedDelivery(unsigned int missedDelivery)
{
    _deliveryFailed.setString("Houses left: " + std::to_string(missedDelivery));
}

void HUD::drawGameOverScreen(sf::RenderWindow& window)
{
   _gameOverScreen.setFinalScore(_scoreText.getString());
   _gameOverScreen.drawGameOverScreen(window);
}