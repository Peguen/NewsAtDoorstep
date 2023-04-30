#ifndef COLLISION_HANDLER_HPP
#define COLLISION_HANDLER_HPP

#include <list>

#include "Definitions.hpp"

#include "NewspaperContainer.hpp"
#include "TargetContainer.hpp"

class CollisionHandler
{
    public:
        CollisionHandler(NewspaperContainer& /*newspaper container*/, TargetContainer& /*target container*/);
        ~CollisionHandler(){};

        void checkForCollisions(std::list<bool>& /*list of new landed/unlanded papers*/);

    private:
        NewspaperContainer&     _newspaperContainer;
        TargetContainer&        _targetContainer;
};

#endif  // COLLISION_HANDLER_HPP