#include "stdafx.h"
#include "Enemy.h"


void Enemy::initEnemyTex()
{
	if (!this->enemyTex.loadFromFile("texTure/allenemy3.png"))
	{
		std::cout << "ERROR" << "\n";
	}
}

void Enemy::initEnemySprite()
{
	this->enemySprite.setTexture(this->enemyTex);
	this->currentFrame = sf::IntRect(0, 0, 144, 60);
	this->enemySprite.setTextureRect(this->currentFrame);
	this->enemySprite.setScale(2.f, 2.f);
	
}

void Enemy::initAnimation()
{
	this->enemyTimer.restart();
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
	this->enemiesX = pos_x;
}

Enemy::~Enemy()
{

}

void Enemy::updateMovement()
{
	enemiesX -= 2;
	this->enemySprite.setPosition(enemiesX, enemySprite.getPosition().y);
}

void Enemy::updateAnimation()
{
	if (this->enemyTimer.getElapsedTime().asSeconds() >= 0.5f)
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 144.f;
		if (this->currentFrame.left >= 576.f)
			this->currentFrame.left = 0;
		this->enemyTimer.restart();
		this->enemySprite.setTextureRect(this->currentFrame);
	}
}

void Enemy::update()
{
	this->updateMovement();
	this->updateAnimation();
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->enemySprite);
}
