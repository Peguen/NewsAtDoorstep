#include <Game.hpp>

#include <iostream>

const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: _window(sf::VideoMode(1920,1080), "News @ doorstep", sf::Style::Close)
, _timeSinceLastTargetSpawn(4.0f)
, _collisionHandler(_newspaperContainer, _targetContainer)
, _hud(_window.getSize())
, _playerScore(0)
, _gameState(STATE::PAUSE)
, _leftMouseButtonHold(false)
, _missedDelivery(0)
, _playedTime(0)
, _spawnTime(TARGET_SPAWN_TIME)
, _soundOn(true)
, _musicOn(true)
{
    _window.setFramerateLimit(60);

    _targetContainer.setBoundaries(810, 1100, _window.getSize().x);
    _audioHandler.playMusic(Music::ID::Reading, true);

    // Texture stuff - will not use texture holder, concept does not work and time issue
    _textureHolder.load(Textures::ID::Player, "./resources/images/Postman_sheet.png");

    // setup player
    _player.setPosition(sf::Vector2f(_window.getSize().x / 2 + 30, _window.getSize().y - _player.getSize().y - 50));
    // just that the textureholder has something to do...
    _player.setTexture(&_textureHolder.get(Textures::ID::Player));
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
    if (MAX_MISS_DELIVERY - _targetContainer.getNotDeliveredCount() <= 0
        && _gameState != STATE::GAMEOVER)
    {
        _gameState = STATE::GAMEOVER;
        _audioHandler.toggleMusic();
        _hud.prepareGameOver();
    }

    switch (_gameState)
    {
        case STATE::RUNNING:
        {
            _playedTime += elapsedTime.asMicroseconds()/1000000.0f;
            if (_leftMouseButtonHold)
            {
                auto currentMousePos = sf::Mouse::getPosition(_window);
                _powerbar.setEndPoint(sf::Vector2f(currentMousePos));
            }

            _newspaperContainer.update(elapsedTime);
            
            // target handling
            _timeSinceLastTargetSpawn += elapsedTime.asMicroseconds()/1000000.0f;
            if (_timeSinceLastTargetSpawn >= _spawnTime)
            {    
                _targetContainer.spawnTarget();
                _timeSinceLastTargetSpawn = 0;
                if (_playedTime > 15 && _spawnTime >= 2)
                {
                    _spawnTime -= 0.5;
                    _playedTime = 0;
                }
            }

            _collisionHandler.checkForCollisions(_paperLandedList);
            if(_soundOn)
            {
                for (auto targetHit: _paperLandedList)
                {
                    if (targetHit)
                        _audioHandler.playSound(SoundEffect::ID::Hit);
                    else
                        _audioHandler.playSound(SoundEffect::ID::Fail);
                }
            }
            handleScoreList();
            _hud.setScore(_playerScore);
            if(_targetContainer.getNotDeliveredCount() > _missedDelivery)
            {
                _missedDelivery = _targetContainer.getNotDeliveredCount();
                if(_soundOn)
                    _audioHandler.playSound(SoundEffect::ID::Oy);
            }
            
            _hud.setMissedDelivery(MAX_MISS_DELIVERY - _missedDelivery);

            _player.animate(elapsedTime);
            break;
        }
        
        default:
            break;
    } 
    
}

void Game::render()
{
    _window.clear();

    switch (_gameState)
    {
        case STATE::RUNNING:
        {
            _floorHandler.drawFloor(_window);
            _targetContainer.drawTargets(_window);

            _newspaperContainer.drawNewspaper(_window);

            if(_leftMouseButtonHold)
                _powerbar.drawPowerBar(_window);	
            
            _player.drawPlayer(_window);
            _hud.drawHUD(_window);
            break;
        }

        case STATE::GAMEOVER:
            _hud.drawGameOverScreen(_window);
            break;

        case STATE::PAUSE:
            _hud.drawPauseScreen(_window);
        default:
            break;
    }
    

    _window.display();
}

void Game::handlePlayerKeyboardInput(sf::Keyboard::Key key, bool isPressed)
{
    if (isPressed)
    {
        switch (key)
        {
            case sf::Keyboard::Space:
            {    
                if (_gameState == STATE::PAUSE || _gameState == STATE::GAMEOVER)
                    reset();
                break;
            }
            case sf::Keyboard::Q:
                _window.close();
                break;
            case sf::Keyboard::M:
            {
                _musicOn = !_musicOn;
                if(_musicOn)
                {
                    if (_gameState == STATE::PAUSE || _gameState == STATE::GAMEOVER)
                        _audioHandler.playMusic(Music::ID::Reading, true);
                    else
                        _audioHandler.playMusic(Music::ID::Running, true);
                }
                else
                {
                    _audioHandler.playMusic(Music::ID::Reading, false);
                    _audioHandler.playMusic(Music::ID::Running, false);
                }
                break;
            }
            case sf::Keyboard::Escape:
                {
                    if (_gameState == RUNNING)
                    {
                        _gameState = STATE::PAUSE;
                        _audioHandler.toggleMusic();
                    }
                    break;
                }
             case sf::Keyboard::C:
                 {
                    if (_gameState == PAUSE && _missedDelivery < MAX_MISS_DELIVERY)
                    {
                        _gameState = STATE::RUNNING;
                        _audioHandler.toggleMusic();
                    }
                    break;
                }
            case sf::Keyboard::S:
                _soundOn = !_soundOn;
                break;
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
                if (_gameState == STATE::RUNNING)
                {
                    auto localPos = sf::Mouse::getPosition(_window);
                    _powerbar.setStartPoint(sf::Vector2f(localPos));
                    _leftMouseButtonHold = true;
                }
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
                if (_gameState == STATE::RUNNING)
                {
                    // safe from failed launch
                    if (std::abs(_powerbar.getBarDirectionVector().x) > 0 || std::abs(_powerbar.getBarDirectionVector().y) > 0)
                    {
                        _newspaperContainer.spawnNewspaper(_player.getPosition(), _powerbar.getBarDirectionVector(), _powerbar.getBarRotationAngle());
                        if (_soundOn)
                            _audioHandler.playSound(SoundEffect::ID::Throw);
                    }
                    _leftMouseButtonHold = false;
                }
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

void Game::handleScoreList()
{
    for (auto landed : _paperLandedList)
    {
        if(landed)
        {
            _playerScore += TARGET_HIT;
        }
        else if (_playerScore >= TARGET_MISS) 
        {
            _playerScore -= TARGET_MISS;
        }
    }
}

void Game::reset()
{
    _gameState = STATE::RUNNING;
    _targetContainer.reset();
    _newspaperContainer.reset();
    _timeSinceLastTargetSpawn = 4.0f;
    _playerScore = 0;
    _audioHandler.toggleMusic();
    _audioHandler.reset();
    _missedDelivery = 0;
    _player.reset();
    _leftMouseButtonHold = false;
    _spawnTime = TARGET_SPAWN_TIME;
    _playedTime = 0;
}