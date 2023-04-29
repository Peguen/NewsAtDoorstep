#include <Game.hpp>

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: _window(sf::VideoMode(1920,1080), "Hello SFML!", sf::Style::Close)
{
    _window.setFramerateLimit(60);

    // set player start position
    _player.setPosition(sf::Vector2f(_window.getSize().x / 2, _window.getSize().y - _player.getSize().y));
}

void Game::run() 
{
    sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(_window.isOpen())
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
            while (_window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::KeyPressed:
				        handlePlayerKeyboardInput(event.key.code, true);
				        break;

			        case sf::Event::KeyReleased:
				        handlePlayerKeyboardInput(event.key.code, false);
				        break;

                    case sf::Event::MouseButtonPressed:
                        handlePlayerMouseInput(event.mouseButton.button, true);
                        break;

                    case sf::Event::MouseButtonReleased:
                        handlePlayerMouseInput(event.mouseButton.button, false);
                        break;

                    case sf::Event::Closed:
                        _window.close();
                        break;
                    default:
                        break;
                }
            }
}

void Game::update(sf::Time elapsedTime)
{
    if (_leftMouseButtonHold)
    {
        auto currentMousePos = sf::Mouse::getPosition(_window);
        _powerbar.setEndPoint(sf::Vector2f(currentMousePos));
    }
}

void Game::render()
{
    _window.clear();
    _player.drawPlayer(_window);
    
    if(_leftMouseButtonHold)
        _powerbar.drawPowerBar(_window);	
	
    _window.display();
}

void Game::handlePlayerKeyboardInput(sf::Keyboard::Key /*pressed key*/, bool isPressed)
{
    // Do some player input handling here
}

#include <iostream>
void Game::handlePlayerMouseInput(sf::Mouse::Button button, bool isPressed)
{
    if (isPressed)
    {
        switch (button)
        {
            case sf::Mouse::Button::Left:
            {
                auto localPos = sf::Mouse::getPosition(_window);
                _powerbar.setStartPoint(sf::Vector2f(localPos));
                _leftMouseButtonHold = true;
                break;
            }
            case sf::Mouse::Button::Right:
                std::cout << "Right button pressed" << std::endl;
                break;
            default:
                break;
        }
    }
    else
    {
        switch (button)
        {
            case sf::Mouse::Button::Left:
                _leftMouseButtonHold = false;
                break;
            case sf::Mouse::Button::Right:
                std::cout << "Right button released" << std::endl;
                break;
            default:
                break;
        }
    }
}