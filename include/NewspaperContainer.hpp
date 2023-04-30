#ifndef NEWSPAPER_CONTAINER_HPP
#define NEWSPAPER_CONTAINER_HPP

#include "Definitions.hpp"
#include "Newspaper.hpp"

class NewspaperContainer
{
    public:
        NewspaperContainer();
        ~NewspaperContainer() {};

        void spawnNewspaper(sf::Vector2f /*start position*/, sf::Vector2f /*direction vector*/, float /*angle*/);
        void drawNewspaper(sf::RenderWindow& /*render window*/);
        void update(sf::Time /*elapsed time*/);

        std::map<unsigned int, std::shared_ptr<Newspaper>>& getContainerRef();

    private:
        void removeOutOfSightTarget(sf::Vector2u /*window size*/);

        std::map<unsigned int, std::shared_ptr<Newspaper>>     _newspaperContainer;
        // we just use an unsigned int to count at the moment
        unsigned int                                           _paperCounter;
};

#endif // NEWSPAPER_CONTAINER_HPP