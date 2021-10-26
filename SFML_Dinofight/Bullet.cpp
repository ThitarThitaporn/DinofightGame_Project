#include "stdafx.h"
#include "Bullet.h"

void Bullet::initBullet()
{

}

Bullet::Bullet()
{
	this->initBullet();
}

Bullet::~Bullet()
{

}

void Bullet::update()
{

}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->bulletFire);
}
