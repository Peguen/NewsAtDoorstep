#include "TargetContainer.hpp"

TargetContainer::TargetContainer()
: _xLowerBound(0)
, _xUpperBound(0)
, _spawnLeft(true)
{

}

void TargetContainer::spawnTarget()
{
    sf::Vector2f spawnPosition(0, 0);
    if (_spawnLeft)
    {
        spawnPosition.x = _xLowerBound / 2;
        _spawnLeft = false;
    }
    else
    {
        spawnPosition.x = (_xMax + _xUpperBound) / 2;    
        _spawnLeft = true;
    }
    auto newTarget = std::make_shared<Target>();
    newTarget->spawn(spawnPosition);
    _targetContainer[_targetCounter++] = newTarget;
}

void TargetContainer::setBoundaries(unsigned int xLower, unsigned int xUpper, unsigned int xMax)
{
    _xLowerBound = xLower;
    _xUpperBound = xUpper;
    _xMax = xMax;
}

void TargetContainer::drawTargets(sf::RenderWindow& window)
{
    removeOutOfSightTarget(window.getSize().y);
    for (auto target : _targetContainer)
        target.second->drawTarget(window);
}

void TargetContainer::removeOutOfSightTarget(unsigned int windowY)
{
    for (auto it = _targetContainer.begin(); it != _targetContainer.end(); )
    {
        if ( it->second->getPosition().y > (windowY + REMOVAL_OFFSET))
            {
                it = _targetContainer.erase(it);
            }
        else
            ++it;
    }
}