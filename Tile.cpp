#include <iostream>
#include <string>
#include "Tile.h"

Tile::Tile()
{}

bool Tile::LoadFromFile(std::string filePath, sf::Vector2f position)
{
	if (!_tileTexture.loadFromFile(filePath))
	{
		std::cout << filePath << " cannot be loaded\n";
		return false;
	}

	_tileSprite.setTexture(_tileTexture);
	_tileSprite.setPosition(position);

	return true;
}

void Tile::Draw(sf::RenderWindow& window)
{
	window.draw(_tileSprite);
}