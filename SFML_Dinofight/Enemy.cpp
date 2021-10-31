#include "stdafx.h"
#include "Enemy.h"


void Enemy::initEnemyTex()
{
	if (!this->enemyTex.loadFromFile("texTure/enemy1.png"))
	{
		std::cout << "ERROR" << "\n";
	}
}

void Enemy::initEnemySprite()
{
	this->enemySprite.setTexture(this->enemyTex);
}

void Enemy::initVariables()
{
	this->type		= 0;
	this->hpMax		= 10;
	this->hp		= 0;
	this->damage	= 1;
	this->points	= 5;
}



Enemy::Enemy()
{
	this->initEnemyTex();
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initEnemyTex();
	this->initVariables();
	this->enemySprite.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{

}

void Enemy::update()
{

}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->enemySprite);
}
