#include "NewspaperContainer.hpp"

NewspaperContainer::NewspaperContainer()
{

}

void NewspaperContainer::drawNewspaper(sf::RenderWindow& window)
{
    removeOutOfSightTarget(window.getSize());
    for (auto paper : _newspaperContainer)
        paper->drawNewspaper(window);

}

void NewspaperContainer::spawnNewspaper(sf::Vector2f startPos, sf::Vector2f dirVec, float angle)
{
    auto newPaper = std::make_shared<Newspaper>();
    newPaper->startFlying(startPos, dirVec, angle);
    _newspaperContainer.push_back(newPaper);
}

void NewspaperContainer::update(sf::Time elapsedTime)
{
    for (auto paper : _newspaperContainer)
        paper->move(elapsedTime);
}

void NewspaperContainer::removeOutOfSightTarget(sf::Vector2u windowSize)
{
    auto it = remove_if(_newspaperContainer.begin(), _newspaperContainer.end(),
    [windowSize](std::shared_ptr<Newspaper> paper){
        if (   (paper->getPosition().y > (windowSize.y + REMOVAL_OFFSET))
            || (paper->getPosition().x > windowSize.x)
            || (paper->getPosition().x < 0))
                return true;
        return false;
    });
    _newspaperContainer.erase(it, _newspaperContainer.end());
}