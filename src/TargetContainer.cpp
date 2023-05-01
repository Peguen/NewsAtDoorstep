#include "TargetContainer.hpp"

TargetContainer::TargetContainer()
: _xLowerBound(0)
, _xUpperBound(0)
, _spawnLeft(true)
, _targetCounter(0)
, _notDeliveredCount(0)
{
    // load the textures
    _leftHouseTexture.loadFromFile("./resources/images/House_left.png");
    _rightHouseTexture.loadFromFile("./resources/images/House_right.png");
}

void TargetContainer::spawnTarget()
{
    auto newTarget = std::make_shared<Target>();
    sf::Vector2f spawnPosition(0, -200);
    if (_spawnLeft)
    {
        spawnPosition.x = std::rand() % (_xLowerBound - 210);
        newTarget->spawn(spawnPosition, _spawnLeft, _leftHouseTexture);
        _spawnLeft = false;
    }
    else
    {
        // 375 -> so that the house is still a bit visible
        spawnPosition.x = (std::rand() % (_xMax - 375 - _xUpperBound)) +  _xUpperBound;  
        newTarget->spawn(spawnPosition, _spawnLeft, _rightHouseTexture);  
        _spawnLeft = true;
    }

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
    for (auto target : _targetContainer){
        target.second->drawTarget(window);
    }
}

void TargetContainer::removeOutOfSightTarget(unsigned int windowY)
{
    for (auto it = _targetContainer.begin(); it != _targetContainer.end(); )
    {
        if ( it->second->getPosition().y > (windowY + REMOVAL_OFFSET))
            {
                if(!it->second->isDelivered())
                    _notDeliveredCount++;
                it = _targetContainer.erase(it);
            }
        else
            ++it;
    }
}

bool TargetContainer::intersects(sf::FloatRect globalBoundsOfPaper)
{
    for (auto target : _targetContainer)
    {
        if(target.second->getGlobalBounds().intersects(globalBoundsOfPaper))
        {   
            target.second->setDelivered();
            return true;
        }
    }
    return false;
}

std::map<unsigned int, std::shared_ptr<Target>>& TargetContainer::getContainerRef()
{
    return _targetContainer;
}

unsigned int TargetContainer::getNotDeliveredCount()
{
    return _notDeliveredCount;
}

void TargetContainer::reset()
{
    _notDeliveredCount = 0;
    _targetCounter = 0;
    _targetContainer.clear();
}