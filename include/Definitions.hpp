#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <map>
#include <SFML/Graphics.hpp>

// Player
#define PLAYER_SPEED 10

// Newspaper
#define START_VELOCITY 3
#define VELOCITY_DEGRADATION 0.05f

// Powerbar
#define BAR_WIDTH 20
#define BAR_OUTLINE_WIDTH 5

// Logic defines
enum DIRECTION
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef std::map<DIRECTION, sf::Vector2f> DirectionMap;

#define SCROLLING_SPEED 2.5f
#define REMOVAL_OFFSET 100

#define TARGET_SPAWN_TIME 2

#endif // DEFINITIONS_HPP