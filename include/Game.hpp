#ifndef GAME_HPP
#define GAME_HPP

#include "Definitions.hpp"
#include <vector>

#include "Player.hpp"
#include "PowerBar.hpp"
#include "Newspaper.hpp"

class Game : private sf::NonCopyable
{
    public:
                                Game();
        void                    run();

    private:
        void                    processEvents();
        void                    update(sf::Time /*elapsed Time*/);
        void                    render();

        void                    handlePlayerKeyboardInput(sf::Keyboard::Key /*key code*/, bool /*pressed or release*/);
        void                    handlePlayerMouseInput(sf::Mouse::Button /*button code*/, bool /*pressed or release*/);

        static const sf::Time                       TimePerFrame;

        sf::RenderWindow                            _window;
        Player                                      _player;
        PowerBar                                    _powerbar;

        DirectionMap                                _directionMap;
        DIRECTION                                   _currentPlayerDirection;
        bool                                        _playerIsMoving{false};

        std::vector<std::shared_ptr<Newspaper>>     _newspaperVector;

        bool                                        _leftMouseButtonHold{false};
};

#endif // GAME_HPP