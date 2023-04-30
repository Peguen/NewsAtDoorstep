#include "CollisionHandler.hpp"

CollisionHandler::CollisionHandler(NewspaperContainer& newspaperContainer, TargetContainer& targetContainer)
: _newspaperContainer(newspaperContainer)
, _targetContainer(targetContainer)
{

}
#include <iostream>
void CollisionHandler::checkForCollisions()
{
    for (auto newspaper : _newspaperContainer.getContainerRef())
    {
        if (newspaper.second->hasLanded())
        {
            if(_targetContainer.intersects(newspaper.second->getGlobalBounds()))
                newspaper.second->setLandedOnTarget(true);
            else
                newspaper.second->setLandedOnTarget(false); 
        }
    }
}