#include <string>
#include "Player.h"

Player::Player(std::string filepath, sf::Vector2f position)
{
	_speed = 2.0f;
	_jumpSpeed = 4.0f;
	_groundWidth = 355.0f;
	_groundHeight = 570.0f;
	_onGroundLeft = true;
	_onGroundRight = true;
	_isFallLeft = false;
	_isFallRight = false;
	_position.x = position.x;
	_position.y = position.y;
	_velocity.x = 0;
	_velocity.y = 0;

	//Is the player on the ground?
	_gravity = 1.0f;

	_source.x = 0;
	_source.y = STOP;

	//Load and set the texture
	_playerTexture.loadFromFile(filepath);

	_playerSprite.setTexture(_playerTexture);
	_playerSprite.setTextureRect(sf::IntRect(_source.x, _source.y, 20, 32));
	_playerSprite.setPosition(sf::Vector2f(_position.x, _position.y));
	_playerSprite.setScale(sf::Vector2f(1.5f, 1.5f));
	_playerSprite.setOrigin(sf::Vector2f(10.0f, 10.0f));

	tile.LoadFromFile("Grass.png", sf::Vector2f(54.0f, 550.0f));
}

void Player::Update(float dt)
{
	//Player movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		_velocity.x = -_speed;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		_velocity.x = _speed;
		_onGroundRight = true;
		_isFallRight = false;
	}
	else
	{
		_velocity.x = 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		_velocity.y = -_jumpSpeed;
	}

	if (_playerSprite.getPosition().y + _playerSprite.getGlobalBounds().height < _groundHeight || _velocity.y < 0)
	{
		_velocity.y += _gravity;
	}
	else
	{
		_playerSprite.setPosition(_playerSprite.getPosition().x, _groundHeight - _playerSprite.getGlobalBounds().height);
		_velocity.y = 0;
	}

	_playerSprite.move(_velocity.x, _velocity.y); 

	//Player falling down on the right
	if (_onGroundRight && !_isFallRight)
	{
		//Pozycja graczaX -> 100.0f
		if (_playerSprite.getPosition().x > tile.GetPosition().x + tile.GetSize().width)
		{
			_playerSprite.move(_playerSprite.getPosition().x, 2.0f); 
		}
	}

	//_playerSprite.move(_velocity.x, _velocity.y);
}

void Player::DrawToTheScreen(sf::RenderWindow& window)
{
	window.draw(_playerSprite);
	tile.Draw(window);
}