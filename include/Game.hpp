#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game : private sf::NonCopyable
{
    public:
                                Game();
        void                    run();

    private:
        void                    processEvents();
        void                    update(sf::Time /*elapsed Time*/);
        void                    render();

        void                    handlePlayerInput(sf::Keyboard::Key /*pressed key*/, bool isPressed);

        static const sf::Time   TimePerFrame;

        sf::RenderWindow        mWindow;
};

#endif // GAME_HPP