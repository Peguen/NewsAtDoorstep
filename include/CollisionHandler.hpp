#ifndef COLLISION_HANDLER_HPP
#define COLLISION_HANDLER_HPP

#include "Definitions.hpp"

#include "NewspaperContainer.hpp"
#include "TargetContainer.hpp"

class CollisionHandler
{
    public:
        CollisionHandler(NewspaperContainer& /*newspaper container*/, TargetContainer& /*target container*/);
        ~CollisionHandler(){};

    private:
        NewspaperContainer*     _newspaperContainer;
        TargetContainer*        _targetContainer;
};

#endif  // COLLISION_HANDLER_HPP