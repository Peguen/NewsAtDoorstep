#include "GameOverScreen.hpp"

GameOverScreen::GameOverScreen()
: _fontHolder(nullptr)
{

}
#include <iostream>
void GameOverScreen::init(FontHolder& fontHolder, sf::Vector2u windowSize)
{
    _fontHolder = &fontHolder;
    _finalScore.setFont(_fontHolder->get(Fonts::Main));
    _finalScore.setCharacterSize(150);
    _finalScore.setPosition(windowSize.x/2, windowSize.y/2);
    _finalScore.setFillColor(sf::Color::Yellow);
}

void GameOverScreen::drawGameOverScreen(sf::RenderWindow& window)
{
    window.draw(_finalScore);
}

void GameOverScreen::setFinalScore(std::string score)
{
    _finalScore.setString(score);
}