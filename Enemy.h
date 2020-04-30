#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(std::string filepath, sf::Vector2f position);

	void Update(float dt);
	void Draw(sf::RenderWindow &window);

	//sf::Vector2f GetPosition() { return _binSprite.getPosition(); }

private:
	sf::Texture _binTexture0;
	sf::Texture _binTexture1;

	sf::Sprite _binSprite;
	sf::Vector2f _position;

	bool _direction;
};