#include "Enemy.h"

Enemy::Enemy(std::string filepath, sf::Vector2f position)
{
	_position.x = position.x;
	_position.y = position.y;

	//Direction right
	_direction = true;

	//Load and set the texture
	_binTexture0.loadFromFile(filepath);
	_binTexture1.loadFromFile("Bin0.png");

	_binSprite.setTexture(_binTexture0);
	_binSprite.setPosition(sf::Vector2f(_position.x, _position.y));
	_binSprite.setScale(sf::Vector2f(0.4f, 0.4f));
	_binSprite.setOrigin(sf::Vector2f(10.0f, 10.0f));
}

void Enemy::Update(float dt)
{
	//AI enemy move right
	if (_direction)
	{
		_binSprite.setTexture(_binTexture0);
		_binSprite.setPosition(_position.x++, _position.y);
		if (_position.x > 335 - _binSprite.getGlobalBounds().width)
		{
			//_binSprite.move(_position.x--, 0.0f);
			_direction = false;
		}
	}

	if (_direction == false)
	{
		_binSprite.setTexture(_binTexture1);
		_binSprite.setPosition(_position.x--, _position.y);
		if (_position.x <= 55)
		{
			//_binSprite.move(_position.x++ * dt, _position.y);
			_direction = true;
		}
	}
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(_binSprite);
}