#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    std::cout << "Hello world!" << std::endl;

    sf::RenderWindow myWindow(sf::VideoMode(1920,1080), "Hello from SFML!", sf::Style::Close);
    sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/60.f);
    while(myWindow.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			sf::Event event;
            while (myWindow.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::Closed:
                        myWindow.close();
                        break;
                    default:
                        break;
                }
            }

		}

		myWindow.clear();
        myWindow.display();
    }
}