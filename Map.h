#pragma once
#include <SFML/Graphics.hpp>

class Map
{
public:
	Map(std::string bgPath, sf::Vector2f bgPosition);

	void Update();
	void Draw(sf::RenderWindow &window);

	sf::FloatRect GetSize() { return _mapSprite.getGlobalBounds(); }
	sf::Vector2f GetPosition() { return _mapSprite.getPosition(); }

private:
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;

	//Clouds
	sf::Texture _cloudTexture;
	sf::Sprite _cloudSprite1;
	sf::Sprite _cloudSprite2;
	sf::Sprite _cloudSprite3;
	bool cloudActive1;
	float cloudSpeed1;
	bool cloudActive2;
	float cloudSpeed2;
	bool cloudActive3;
	float cloudSpeed3;

	sf::Texture _wallLeftTexture;
	sf::Sprite _wallLeftSprite;

	sf::Texture _wallRightTexture;
	sf::Sprite _wallRightSprite;

	sf::Texture _mapTexture;
	sf::Sprite _mapSprite;

	sf::Clock _clock;
	float _deltaTime;
};