#ifndef BULLET_H
#define BULLET_H

#include"stdafx.h";


#endif // 


#pragma once
class Bullet
{
private:
	sf::Sprite bulletFire;
	sf::Texture bulletTex;

	sf::Vector2f direction;
	float movementSpeed;
	void initBullet();
	void initSprite();


public:
		Bullet();
		Bullet(float pos_x,float pos_y,float dir_X,float dir_Y,float movement_speed);
		virtual ~Bullet();

		//Accessore
		const sf::FloatRect getBounds() const;

		void update();
		void render(sf::RenderTarget& target);


};

