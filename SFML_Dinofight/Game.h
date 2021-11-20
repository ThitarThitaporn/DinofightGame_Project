#pragma once
#include<map>
#include"stdafx.h"
#include"player.h"
#include"Bullet.h"
#include"Enemy.h"
#include"PlayerGUI.h"
#include"Menu.h"
#include"HeartItem.h"
#include"Chest.h"
#include"Endgame.h"
#include"Stone.h"
#include"Endgame.h"
#include"score.h"

class Game
{
private:
	int end;
	sf::RenderWindow window;
	sf::Event ev;

	sf::Clock bulletTime;
	sf::Clock enemiesTime;
	
	//Username
	sf::Texture nameboardTex;
	sf::Sprite nameboardSprite;
	std::string player_name = "";
	std::vector<char> username;
	bool namestate = false;


	//word bg
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	
	float backgroundX = 0;

	//Resources
	std::map<std::string,sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//enemy
	Enemy* enemy;
	int enemiseCount = 0 ;
	std::vector<Enemy*> enemys;

	//Player
	Player* player;

	//Bullet
	Bullet* bullet;
	
	
	//GUI
	PlayerGUI* playerGUI;
	PlayerGUI* hpBar;

	//endgame
	Endgame* endGame;

	//heartItem
	std::vector<HeartItem*> heartItem;
	sf::Clock randHeart;
	sf::Clock timeHeart;
	float heartX = 0;
	float heartY = 0;

	//Chest
	std::vector<Chest*> chest;
	sf::Clock randChest;
	sf::Clock timeChest;
	float ChestX = 0;
	float ChestY = 0;

	//Stone
	std::vector<Stone*> stone;
	sf::Clock delayStone;
	sf::Clock randStone;
	sf::Clock timeStone;
	int countStone = 0;
	float StoneX = 0;

	//Score
	sf::Clock timeText;
	float timeUS;
	score scoreboard;
	std::string name;
	std::string user_name;
	sf::Text US_name;


	bool over();
	void reset();

	//game over
	Endgame* gameOver;


	//menu
	Menu* menu;
	bool GameRun = false;

	void initWindow();
	void initplayer();
	void initBullet();
	void initEnemy();
	void initHpBar();
	void initGUI();
	void initUsername();
	void initGameover();

	void initWorld();



public:

	//Functions
	Game();
	virtual ~Game();

	void run();
	void getName(std::string name);

	//Functions

	void collision();
	void updateHeartItem();
	void updateChest();
	void updateStone();
	void updateHpBar();
	void updateBullets();
	void updateEnemy();
	void updateplayer();
	void updateWorld();
	

	void update();

	void renderUsername();
	void renderGUI();
	void renderHeartItem();
	void renderChest();
	void renderStone();
	void renderPlayer();
	void renderBullet();
	void renderEnemy();
	void renderSavescore();
	void renderEndgame();
	void renderWorld();
	void renderGameover();
	void render();
	const sf::RenderWindow& getWindow() const;
};