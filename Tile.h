#pragma once
#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile();

	bool LoadFromFile(std::string filePath, sf::Vector2f position);
	void Draw(sf::RenderWindow& window);

	sf::FloatRect GetSize() { return _tileSprite.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return _tileSprite.getPosition(); }

private:
	sf::Texture _tileTexture;
	sf::Sprite _tileSprite;
	sf::Vector2f _position;
};