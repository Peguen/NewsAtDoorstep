#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <list>

#include "Definitions.hpp"
#include "Player.hpp"
#include "PowerBar.hpp"
#include "NewspaperContainer.hpp"
#include "TargetContainer.hpp"
#include "CollisionHandler.hpp"
#include "HUD.hpp"
#include "GameOverScreen.hpp"

class Game : private sf::NonCopyable
{
    public:
        enum STATE
        {
            RUNNING,
            GAMEOVER
        };
                                Game();
        void                    run();

    private:
        void                    processEvents();
        void                    update(sf::Time /*elapsed Time*/);
        void                    render();

        void                    handlePlayerKeyboardInput(sf::Keyboard::Key /*key code*/, bool /*pressed or release*/);
        void                    handlePlayerMouseInput(sf::Mouse::Button /*button code*/, bool /*pressed or release*/);
        void                    handleScoreList();
        void                    reset();

        static const sf::Time                       TimePerFrame;

        sf::RenderWindow                            _window;
        Player                                      _player;
        PowerBar                                    _powerbar;

        NewspaperContainer                          _newspaperContainer;
        TargetContainer                             _targetContainer;
        CollisionHandler                            _collisionHandler;

        HUD                                         _hud;
        unsigned int                                _playerScore;
        std::list<bool>                             _paperLandedList;

        float                                       _timeSinceLastTargetSpawn;

        bool                                        _leftMouseButtonHold;
        STATE                                       _gameState;
};

#endif // GAME_HPP