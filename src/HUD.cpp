#include "HUD.hpp"

HUD::HUD(sf::Vector2u windowSize)
: _windowSize(windowSize)
{
    loadFonts();

    setText(_scoreText);
    setText(_deliveryFailed);
    setText(_highscore);
    setText(_howToPlay);

    setupHowToPlay();

    _scoreText.setPosition(100, 10.f);
    _deliveryFailed.setPosition(100, 70.f);
    _highscore.setPosition(windowSize.x/3, windowSize.y/4);
    
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

void HUD::drawPauseScreen(sf::RenderWindow& window)
{
    window.draw(_howToPlay);
}

void HUD::setMissedDelivery(unsigned int missedDelivery)
{
    _deliveryFailed.setString("Houses: " + std::to_string(missedDelivery));
}

void HUD::prepareGameOver()
{
    _isNewRecord = false;
    if (!_highscoreList.empty() && (_highscoreList[0] < _score ))
        _isNewRecord = true;

     _highscoreList.push_back(_score);
    std::sort(_highscoreList.begin(), _highscoreList.end(), std::greater<int>());  

    std::string highscoreText = "Game Over!\nYour last score was: " + std::to_string(_score) + "\n";
    unsigned int counter = 1;
    for (auto highscore : _highscoreList)
    {
        highscoreText += std::to_string(counter++) + ": " + std::to_string(highscore) + "\n";
        if (counter > 5)
            break;
    }
    highscoreText += "\n\n\nPress Space to restart the game.";
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
    text.setCharacterSize(50u);
}

void HUD::setupHowToPlay()
{
    std::string description = "Welcome to \"News @ Doorstep\"\n";

    description += "News @ Doorstep is an endlessrunner game. You have to throw the mail to the doorsteps of the houses. \n";
    description += "20 points for delivering.\n";
    description += "-5 points for a missed delivery.\n";
    description += "Game will end when 5 houses do not receive the newspaper.\n";
    description += "\nControls:\n";
    description += "Left mouse button:\n\t1. click and hold \n\t2. drag for velocity and direction\n\t3. release to throw\n";
    description += "\nSpacebar: restart the game\n";
    description += "ESC: pause the game\n";
    description += "C: continue game\n";
    
    description += "\nQ: quit the game\n";

    description += "\nM: toggle music\n";
    description += "S: toggle sounds\n";

    _howToPlay.setCharacterSize(30u);
    _howToPlay.setPosition(50, 150);
    _howToPlay.setString(description);
}