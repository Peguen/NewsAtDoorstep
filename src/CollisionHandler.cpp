#include "CollisionHandler.hpp"

CollisionHandler::CollisionHandler(NewspaperContainer& newspaperContainer, TargetContainer& targetContainer)
: _newspaperContainer(newspaperContainer)
, _targetContainer(targetContainer)
{

}
#include <iostream>
void CollisionHandler::checkForCollisions(std::list<bool>& landedList)
{
    landedList.clear();
    for (auto newspaper : _newspaperContainer.getContainerRef())
    {
        if (newspaper.second->hasLanded() && newspaper.second->isMarkedForScore())
        {
            if(_targetContainer.intersects(newspaper.second->getGlobalBounds()))
                newspaper.second->setLandedOnTarget(true);
            else
                newspaper.second->setLandedOnTarget(false); 

            landedList.push_back(newspaper.second->getScoreValue());
        }
    }
}