#pragma once
class Coin
{
private:
	sf::Sprite coin;
	sf::Texture coinTex;

	void initSprite();
	void initTextures();
public:
	virtual ~Coin();
	Coin(float x, float y);
	const sf::Vector2f getPos();
	const sf::FloatRect getGlobalbonds();
	void setPosition(float x, float y);

	void update();
	void render(sf::RenderTarget& target);
};

