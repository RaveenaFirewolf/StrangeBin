#include <iostream>
using namespace std;

#include "Map.h"
#include "Tile.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	//SCREEN_WIDTH -> 800, SCREEN_HEIGHT -> 600
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Strange bin");

	//Map class
	Map ground1("Bg.png", sf::Vector2f(0.0f, 0.0f));

	Tile lineGrass;
	Tile grass;

	lineGrass.LoadFromFile("LineGrass.png", sf::Vector2f(400.0f, 390.0f));
	grass.LoadFromFile("Grass1.png", sf::Vector2f(580.0f, 370.0f));

	//Player class
	Player player("PlayerSprite.png", sf::Vector2f(10.0f, 140.0f));
	Enemy enemy("Bin.png", sf::Vector2f(54.0f, 510.0f));

	sf::Clock clock;

	//Game loop
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (ev.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
				break;
			default:
				break;
			}
		}

		////Player movement
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		//{
		//	isJumping = true;
		//}

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		//{
		//	player.GetSprite().move(-2.0f, 0.0f);
		//	onGroundLeft = true;
		//	isFallLeft = false;
		//}
		//
		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		//{
		//	player.GetSprite().move(2.0f, 0.0f);
		//	onGroundRight = true;
		//	isFallRight = false;
		//}
	
		////Player falling down on the left
		//if (onGroundLeft && !isFallLeft)
		//{
		//	//Pozycja graczaX -> 100.0f
		//	if (player.GetPosition().x <= 68.0f)
		//	{
		//		player.SetPosition(sf::Vector2f(68.0f, player.GetPosition().y));
		//	}
		//}

		////Player falling down on the right
		//if (onGroundRight && !isFallRight)
		//{
		//	//Pozycja graczaX -> 100.0f
		//	if (player.GetPosition().x > tile.GetPosition().x + tile.GetSize().width)
		//	{
		//		player.GetSprite().move(0.0f, 4.0f);
		//	}
		//}

		//Ile czasu minelo od ostatniego utworzenia zegara
		float deltaTime = clock.getElapsedTime().asSeconds();

		ground1.Update();
		player.Update(deltaTime);
		enemy.Update(deltaTime);

		window.clear();

		//Draw a stuff here
		ground1.Draw(window);
		lineGrass.Draw(window);
		grass.Draw(window);
		player.DrawToTheScreen(window);
		enemy.Draw(window);

		window.display();

		clock.restart();
	}

	return 0;
}