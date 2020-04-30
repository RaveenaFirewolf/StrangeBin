#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Tile.h"

class Player
{
public:
	Tile tile;

	enum Direction { STOP };
	Player(std::string filepath, sf::Vector2f position);

	void Update(float dt);
	void DrawToTheScreen(sf::RenderWindow &window);

	sf::Sprite &GetSprite() { return _playerSprite; }
	sf::FloatRect GetGlobalBounds() { return _playerSprite.getGlobalBounds(); }

	void SetPosition(sf::Vector2f position) { _playerSprite.setPosition(position); }
	sf::Vector2f GetPosition() { return _playerSprite.getPosition(); }

private:
	sf::Texture _playerTexture;
	sf::Sprite _playerSprite;
	sf::Vector2i _source;
	sf::Vector2f _position;
	sf::Vector2f _velocity;

	bool _onGroundLeft;
	bool _onGroundRight;
	bool _isFallLeft;
	bool _isFallRight;

	float _speed;
	float _groundWidth;
	float _groundHeight;

	//How higth is the player is jumping
	float _jumpSpeed;
	float _gravity;
};