#pragma once
#include<map>
#include"stdafx.h"
#include"player.h"
#include"Bullet.h"
#include"Enemy.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;

	//word bg
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	
	float backgroundX = 0;

	//Resources
	std::map<std::string,sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//enemy
	Enemy* enemy;
	//Player
	Player* player;

	//Bullet
	Bullet* bullet;
	
	//Enemies
	int enemiseCount= 0 ;
	std::vector<Enemy*> enemys;
	//Enemy* enemy; 

	void initWindow();
	void initplayer();
	void initBullet();
	void initEnemy();
	void initWorld();



public:

	//Functions
	Game();
	virtual ~Game();
	//Functions

	void collision();
	void updateBullets();
	void updateEnemy();
	void updateplayer();
	/*void updateBullet();*/
	void updateWorld();
	

	//void updateCollision();
	void update();
	void renderPlayer();
	void renderBullet();
	void renderEnemy();
	void renderWorld();
	void render();
	const sf::RenderWindow& getWindow() const;
};