#include <Game.hpp>

#include <iostream>

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: _window(sf::VideoMode(1920,1080), "Hello SFML!", sf::Style::Close)
{
    _window.setFramerateLimit(60);

    // set player start position
    _player.setPosition(sf::Vector2f(_window.getSize().x / 2, _window.getSize().y - _player.getSize().y));

    _directionMap[DIRECTION::UP] = sf::Vector2f(0,-1);
    _directionMap[DIRECTION::DOWN] = sf::Vector2f(0,1);
    _directionMap[DIRECTION::LEFT] = sf::Vector2f(-1,0);
    _directionMap[DIRECTION::RIGHT] = sf::Vector2f(1,0);
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

    // removeOutOfScreenEntities();

    if (_playerIsMoving)
        _player.move(_directionMap[_currentPlayerDirection]);

    for (auto& paper : _newspaperVector)
    {
        paper->move(elapsedTime);
    }
}

void Game::render()
{
    _window.clear();
    _player.drawPlayer(_window);
    
    if(_leftMouseButtonHold)
        _powerbar.drawPowerBar(_window);	
    
    auto it = remove_if(_newspaperVector.begin(), _newspaperVector.end(),
        [](std::shared_ptr<Newspaper> paper){
            return paper->removePaper();
          });
    _newspaperVector.erase(it, _newspaperVector.end());

    for (auto& paper : _newspaperVector)
    {
        paper->drawNewspaper(_window);
    }
	
    _window.display();
}

void Game::handlePlayerKeyboardInput(sf::Keyboard::Key key, bool isPressed)
{
    if (isPressed)
    {
        switch (key)
        {
            case sf::Keyboard::A:
            {
                _currentPlayerDirection = DIRECTION::LEFT;
                _playerIsMoving = true;
                break;
            }
            case sf::Keyboard::D:
            {
                _currentPlayerDirection = DIRECTION::RIGHT;
                _playerIsMoving = true;
                break;
            }
            default:
                break;
        }
    }
    else
    {
        switch (key)
        {
            case sf::Keyboard::A:
            {
                _playerIsMoving = false;
                break;
            }
            case sf::Keyboard::D:
            {
                _playerIsMoving = false;
                break;
            }
            default:
                break;
        }
    }
}

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
            {
                auto new_paper = std::make_shared<Newspaper>();
                new_paper->startFlying(_player.getPosition(), _powerbar.getBarDirectionVector(), _powerbar.getBarRotationAngle(), _window.getSize());
                _newspaperVector.push_back(new_paper);
                _leftMouseButtonHold = false;
                break;
            }
            case sf::Mouse::Button::Right:
                std::cout << "Right button released" << std::endl;
                break;
            default:
                break;
        }
    }
}