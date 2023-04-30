#include "HUD.hpp"

HUD::HUD(sf::Vector2u windowSize)
: _windowSize(windowSize)
{
    loadFonts();

    setText(_scoreText);
    setText(_deliveryFailed);
    setText(_highscore);

    _scoreText.setPosition(windowSize.x/2 - 100, 10.f);
    _deliveryFailed.setPosition(windowSize.x/2 - 100, 70.f);
    _highscore.setPosition(windowSize.x/3, windowSize.y/3);
    
    _newRecord.setFont(_fontHolder.get(Fonts::Main));
    _newRecord.setPosition(windowSize.x/3, windowSize.y - 100);
    _newRecord.setString("NEW RECORD!");
    _newRecord.setFillColor(sf::Color::Magenta);
    _newRecord.setCharacterSize(50u);

}

void HUD::loadFonts()
{
    _fontHolder.load(Fonts::Main, "./resources/fonts/Raleway-ExtraBold.ttf");
}

void HUD::setScore(unsigned int score)
{
    _score = score;
    _scoreText.setString("Score: " + std::to_string(score));
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

void HUD::prepareGameOver()
{
    _isNewRecord = false;
    if (!_highscoreList.empty() && (_highscoreList[0] < _score ))
        _isNewRecord = true;

     _highscoreList.push_back(_score);
    std::sort(_highscoreList.begin(), _highscoreList.end(), std::greater<int>());  

    std::string highscoreText = "Game Over!\n";
    unsigned int counter = 1;
    for (auto highscore : _highscoreList)
    {
        highscoreText += std::to_string(counter++) + ": " + std::to_string(highscore) + "\n";
        if (counter > 5)
            break;
    }
    _highscore.setString(highscoreText);
}

void HUD::drawGameOverScreen(sf::RenderWindow& window)
{
    window.draw(_highscore);
    if(_isNewRecord)
        window.draw(_newRecord);
}

void HUD::setText(sf::Text& text)
{
    text.setFont(_fontHolder.get(Fonts::Main));
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20u);
}