#pragma once
#include<map>
#include"stdafx.h"
#include"player.h"
#include"Bullet.h"
#include"Enemy.h"
#include"PlayerGUI.h"
#include"Menu.h"
#include"HeartItem.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;

	sf::Clock bulletTime;
	sf::Clock enemiesTime;

	//word bg
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	
	float backgroundX = 0;

	//Resources
	std::map<std::string,sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//enemy
	Enemy* enemy;

	//Enemies
	int enemiseCount = 0 ;
	std::vector<Enemy*> enemys;

	//Player
	Player* player;

	//Bullet
	Bullet* bullet;
	
	
	//GUI
	PlayerGUI* playerGUI;
	PlayerGUI* hpBar;

	//heartItem
	std::vector<HeartItem*> heartItem;
	sf::Clock randHeart;
	sf::Clock timeHeart;
	float heartX = 0;
	float heartY = 0;

	//menu
	Menu* menu;
	bool GameRun = false;

	void initWindow();
	void initplayer();
	void initBullet();
	void initEnemy();
	void initHpBar();
	void initGUI();

	void initWorld();



public:

	//Functions
	Game();
	virtual ~Game();
	//Functions

	void collision();
	void updateHeartItem();
	void updateHpBar();
	void updateBullets();
	void updateEnemy();
	void updateplayer();


	void updateWorld();
	//void updateCollision();
	void update();

	void renderGUI();
	void renderHeartItem();
	void renderPlayer();
	void renderBullet();
	void renderEnemy();
	void renderWorld();
	void render();
	const sf::RenderWindow& getWindow() const;
};