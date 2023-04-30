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

    private:
        void removeOutOfSightTarget(sf::Vector2u /*window size*/);

        std::vector<std::shared_ptr<Newspaper>>     _newspaperContainer;
};

#endif // NEWSPAPER_CONTAINER_HPP