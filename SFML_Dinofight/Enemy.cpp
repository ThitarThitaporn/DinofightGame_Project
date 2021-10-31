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
	this->enemySprite.setScale(0.5f, 0.5f);
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
	printf("A");
	this->initEnemyTex();
	this->initVariables();
	
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initEnemyTex();
	this->initEnemySprite(); //forget
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
