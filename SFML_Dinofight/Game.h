#pragma once
#include<map>
#include"stdafx.h"
#include"player.h"
#include"Bullet.h"
#include"Enemy.h"
#include"PlayerGUI.h"
#include"Menu.h"
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
	//Player
	Player* player;

	//Bullet
	Bullet* bullet;
	
	//Enemies
	int enemiseCount = 0 ;
	std::vector<Enemy*> enemys;
	//Enemy* enemy; 

	//GUI
	PlayerGUI* playerGUI;
	PlayerGUI* hpBar;

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
	void updateHpBar();
	void updateBullets();
	void updateEnemy();
	void updateplayer();

	void updateWorld();
	//void updateCollision();
	void update();

	void renderGUI();
	void renderPlayer();
	void renderBullet();
	void renderEnemy();
	void renderWorld();
	void render();
	const sf::RenderWindow& getWindow() const;
};