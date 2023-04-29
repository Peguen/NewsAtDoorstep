#include <Game.hpp>

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: mWindow(sf::VideoMode(1920,1080), "Hello SFML!", sf::Style::Close)
{

}

void Game::run() 
{
    sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

            processEvents();
            update(TimePerFrame);
		}

		render();
    }
}

void Game::processEvents() 
{
    sf::Event event;
            while (mWindow.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::KeyPressed:
				        handlePlayerInput(event.key.code, true);
				        break;

			        case sf::Event::KeyReleased:
				        handlePlayerInput(event.key.code, false);
				        break;

                    case sf::Event::Closed:
                        mWindow.close();
                        break;
                    default:
                        break;
                }
            }
}

void Game::update(sf::Time elapsedTime)
{
    // Do some game algo stuff here
}

void Game::render()
{
    mWindow.clear();	
	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key /*pressed key*/, bool isPressed)
{
    // Do some player input handling here
}