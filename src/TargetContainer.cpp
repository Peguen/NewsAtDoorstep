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
    _targetContainer.push_back(newTarget);
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
        target->drawTarget(window);
}

void TargetContainer::removeOutOfSightTarget(unsigned int windowY)
{
    auto it = remove_if(_targetContainer.begin(), _targetContainer.end(),
    [windowY](std::shared_ptr<Target> target){
        return target->getPosition().y > windowY;
    });
    _targetContainer.erase(it, _targetContainer.end());
}