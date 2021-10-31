#ifndef ENEMY_H
#define ENEMY_H
#include "stdafx.h"

class Enemy
{
private:
	sf::Sprite enemySprite;
	sf::Texture enemyTex;
	
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initEnemyTex();
	void initEnemySprite();
	void initVariables();

public:
	Enemy();
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//functions
	void update();
	void render(sf::RenderTarget& target);
};


#endif // !ENEMY_H