#include "NewspaperContainer.hpp"

NewspaperContainer::NewspaperContainer()
: _paperCounter(0)
{

}

void NewspaperContainer::drawNewspaper(sf::RenderWindow& window)
{
    removeOutOfSightTarget(window.getSize());
    for (auto paper : _newspaperContainer)
        paper.second->drawNewspaper(window);

}

void NewspaperContainer::spawnNewspaper(sf::Vector2f startPos, sf::Vector2f dirVec, float angle)
{
    auto newPaper = std::make_shared<Newspaper>();
    newPaper->startFlying(startPos, dirVec, angle);
    _newspaperContainer[_paperCounter++] = newPaper;
}

void NewspaperContainer::update(sf::Time elapsedTime)
{
    for (auto paper : _newspaperContainer)
        paper.second->move(elapsedTime);
}

void NewspaperContainer::removeOutOfSightTarget(sf::Vector2u windowSize)
{
    for (auto it = _newspaperContainer.begin(); it != _newspaperContainer.end(); )
    {
        if (   (it->second->getPosition().y > (windowSize.y + REMOVAL_OFFSET))
            || (it->second->getPosition().x > windowSize.x)
            || (it->second->getPosition().x < 0))
            {
                it = _newspaperContainer.erase(it);
            }
        else
            ++it;
    }
}

std::map<unsigned int, std::shared_ptr<Newspaper>>& NewspaperContainer::getContainerRef()
{
    return _newspaperContainer;
}