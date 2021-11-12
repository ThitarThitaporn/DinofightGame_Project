#pragma once
#include"stdafx.h"

class Chest
{

private:
	sf::Sprite chestSprite;
	sf::Texture chestTex;
	float chestX;

	//hitbox
	sf::RectangleShape chestHitbox;

	void initHitbox();
	void initSprite();
	void initTexture();

	void updateHitbox();
	void updateMovement();


public:
	virtual ~Chest();

	Chest(float x, float y);

	const sf::Vector2f getPosition();
	const sf::FloatRect getBounds() const;
	void setPosition(float x, float y);

	//hitbox
	const sf::FloatRect getBoundsHitbox();

	void update();
	void render(sf::RenderTarget& target);




};

