#pragma once

#include"stdafx.h"

class Stone
{


private:
	sf::Sprite stoneSprite;
	sf::Texture stoneTex;

	float StoneX;
	//Hitbox
	sf::RectangleShape stoneHitbox;

	//rotate
	float stoneRotate = 0 ;

	void initHitbox();
	void initSprite();
	void initTexture();

public:
	virtual ~Stone();

	Stone(float x, float y);
	const sf::Vector2f getPosition();
	const sf::FloatRect getGlobalbounds();
	void setPosition(float x, float y);

	//Hitbox
	const sf::FloatRect getGlobalBoundsHitbox() const;

	void update();
	void updateHitbox();
	void updateMovement();
	void render(sf::RenderTarget& target);
};








