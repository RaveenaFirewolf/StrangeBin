#include <string>
#include "Map.h"

Map::Map(std::string bgPath, sf::Vector2f bgPosition)
{
	_bgTexture.loadFromFile(bgPath);

	_bgSprite.setTexture(_bgTexture);
	_bgSprite.setPosition(bgPosition.x, bgPosition.y);

	_cloudTexture.loadFromFile("Cloud.png");

	_cloudSprite1.setTexture(_cloudTexture);
	_cloudSprite2.setTexture(_cloudTexture);
	_cloudSprite3.setTexture(_cloudTexture);

	_cloudSprite1.setPosition(sf::Vector2f(0.0f, 0.0f));
	_cloudSprite2.setPosition(sf::Vector2f(0.0f, 50.0f));
	_cloudSprite3.setPosition(sf::Vector2f(0.0f, 100.0f));

	_cloudSprite1.setScale(sf::Vector2f(0.6f, 0.6f));
	_cloudSprite2.setScale(sf::Vector2f(0.6f, 0.6f));
	_cloudSprite3.setScale(sf::Vector2f(0.6f, 0.6f));

	_wallLeftTexture.loadFromFile("LeftWall.png");
	_wallLeftSprite.setTexture(_wallLeftTexture);
	_wallLeftSprite.setPosition(sf::Vector2f(0.0f, 382.0f));

	_wallRightTexture.loadFromFile("RightWall.png");
	_wallRightSprite.setTexture(_wallRightTexture);
	_wallRightSprite.setPosition(sf::Vector2f(745.0f, 382.0f));

	cloudActive1 = false;
	cloudActive2 = false;
	cloudActive3 = false;
	cloudSpeed1 = 0.0f;
	cloudSpeed2 = 0.0f;
	cloudSpeed3 = 0.0f;
}

void Map::Update()
{
	_deltaTime = _clock.restart().asSeconds();

	//Manage the cloud
	if (!cloudActive1)
	{
		//How fast is the cloud
		srand((int)time(0) * 10);
		cloudSpeed1 = rand() % 300;

		//How hight is the cloud
		srand((int)time(0) * 10);
		float cloudHeight = rand() % 200;
		_cloudSprite1.setPosition(-500, cloudHeight);
		cloudActive1 = true;
	}
	else
	{
		//Set the position of the cloud
		_cloudSprite1.setPosition(_cloudSprite1.getPosition().x + (cloudSpeed1 * _deltaTime), _cloudSprite1.getPosition().y);

		if (_cloudSprite1.getPosition().x > 800)
		{
			cloudActive1 = false;
		}
	}

	if (!cloudActive2)
	{
		//How fast is the cloud
		srand((int)time(0) * 30);
		cloudSpeed2 = rand() % 300;

		//How hight is the cloud
		srand((int)time(0) * 20);
		float cloudHeight = (rand() % 300) - 150;
		_cloudSprite2.setPosition(-500, cloudHeight);
		cloudActive2 = true;
	}
	else
	{
		//Set the position of the cloud
		_cloudSprite2.setPosition(_cloudSprite2.getPosition().x + (cloudSpeed2 * _deltaTime), _cloudSprite2.getPosition().y);

		if (_cloudSprite2.getPosition().x > 800)
		{
			cloudActive2 = false;
		}
	}

	if (!cloudActive3)
	{
		//How fast is the cloud
		srand((int)time(0) * 50);
		cloudSpeed3 = rand() % 300;

		//How hight is the cloud
		srand((int)time(0) * 30);
		float cloudHeight = (rand() % 450) - 150;
		_cloudSprite3.setPosition(-500, cloudHeight);
		cloudActive3 = true;
	}
	else
	{
		//Set the position of the cloud
		_cloudSprite3.setPosition(_cloudSprite3.getPosition().x + (cloudSpeed3 * _deltaTime), _cloudSprite3.getPosition().y);

		if (_cloudSprite3.getPosition().x > 800)
		{
			cloudActive3 = false;
		}
	}
}

void Map::Draw(sf::RenderWindow& window)
{
	window.draw(_bgSprite);
	window.draw(_cloudSprite1);
	window.draw(_cloudSprite2);
	window.draw(_cloudSprite3);
	window.draw(_wallLeftSprite);
	window.draw(_wallRightSprite);
}