#include "stdafx.h"
#include "Bullet.h"

void Bullet::initBullet()
{
	if (!this->bulletTex.loadFromFile("texTure/fireBall1.png"))
	{
		std::cout << "ERROR" << "\n";
	}
}

void Bullet::initSprite()
{
	this->bulletFire.setTexture(this->bulletTex);
	this->bulletFire.setScale(0.18f, 0.18f);

}

Bullet::Bullet()
{
	this->initBullet();
}

Bullet::Bullet( float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->initBullet();
	this->initSprite();
	
	this->bulletFire.setPosition(pos_x, pos_y);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementSpeed = movement_speed;
}

Bullet::~Bullet()
{

}

const sf::FloatRect Bullet::getBounds() const
{
	return this->bulletFire.getGlobalBounds();
}

void Bullet::update()
{
	//Movement 
	this->bulletFire.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->bulletFire);
}
