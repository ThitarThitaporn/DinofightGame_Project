#pragma once
#include"stdafx.h"

class HeartItem
{

private:
	sf::Sprite heartSprite;
	sf::Texture heartTex;
	float heartX;

	//hitbox
	sf::RectangleShape heartHitbox;

	void initHitbox();
	void initSprite();
	void initTexture();

	void updateHitbox();
	void updateMovement();

public:
	virtual ~HeartItem();

	HeartItem(float x, float y);

	const sf::Vector2f getPosition();
	const sf::FloatRect getBounds() const;
	void setPosition(float x, float y);

	//hitbox
	const sf::FloatRect getBoundsHitbox();

	void update();
	void render(sf::RenderTarget& target);


};

