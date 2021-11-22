#pragma once
#include"Player.h"
#include"stdafx.h"
class Shield
{
private:
	Player* player;

	sf::Sprite shield;
	sf::Texture shieldTex;
	float shieldX;

	sf::Sprite aura;
	sf::Texture auraTex;

	//Hitbox
	sf::RectangleShape shieldHitbox;

	void initHitbox();
	void initSprite();
	void initTexture();

	void updateHitbox();
	void updateMovement();

public:
	virtual ~Shield();

	Shield(float x, float y);

	const sf::Vector2f getPosition();
	const sf::FloatRect getGlobalbounds() const;
	void setPosition(float x, float y);

	//Aura
	void setPositionAura(float x, float y);

	//Hitbox
	const sf::FloatRect getGlobalBoundsHitbox() const;

	void updateAura();
	void update();

	void renderAura(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);

};

