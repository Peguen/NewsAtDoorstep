#ifndef TARGET_CONTAINER_HPP
#define TARGET_CONTAINER_HPP

#include "Definitions.hpp"
#include "Target.hpp"

class TargetContainer
{
    public:
        TargetContainer();
        ~TargetContainer() {};

        void    setBoundaries(unsigned int	/*x lower*/, unsigned int /*x upper*/, unsigned int /*x max*/);
        void    spawnTarget();

        void    drawTargets(sf::RenderWindow& /*render window*/);
        
    private:
        void    removeOutOfSightTarget(unsigned int /*window size y*/);

        std::vector<std::shared_ptr<Target>>    _targetContainer;
        unsigned int                            _xLowerBound;
        unsigned int                            _xUpperBound;
        unsigned int                            _xMax;
        bool                                    _spawnLeft;
};

#endif // TARGET_CONTAINER_HPP