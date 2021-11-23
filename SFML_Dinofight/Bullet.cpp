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

void Bullet::initHitbox()
{
	this->hitboxBullet.setOutlineColor(sf::Color::Blue);
	this->hitboxBullet.setOutlineThickness(2.f);
	this->hitboxBullet.setFillColor(sf::Color::Transparent);
	this->hitboxBullet.setSize(sf::Vector2f( 90.f, 70.f));
}

void Bullet::updateHitbox()
{
	this->hitboxBullet.setPosition(bulletFire.getPosition().x,bulletFire.getPosition().y+5);

}

Bullet::Bullet()
{
	this->initBullet();
}

Bullet::Bullet( float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->initBullet();
	this->initSprite();
	this->initHitbox();

	this->bulletFire.setPosition(pos_x + 210, pos_y + 100);
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

const sf::Vector2f Bullet::getPosition() const
{
	return this->bulletFire.getPosition();
}

const sf::FloatRect Bullet::getBoundsHitbox() const
{
	return this->hitboxBullet.getGlobalBounds();
}

void Bullet::update()
{
	//Movement 
	this->bulletFire.move(this->movementSpeed * this->direction);
	this->updateHitbox();
}

void Bullet::render(sf::RenderTarget& target)
{
	target.draw(this->bulletFire);
	//target.draw(this->hitboxBullet);
}
