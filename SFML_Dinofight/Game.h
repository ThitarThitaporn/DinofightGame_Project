#pragma once
#include"stdafx.h"
#include"player.h"
#include"Bullet.h"
class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;

	//word bg
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	
	float backgroundX = 0;

	Player* player;
	Bullet* bullet;
	

	void initWindow();
	void initplayer();
	void initWorld();
	void initBullet();



public:

	//Functions
	Game();
	virtual ~Game();
	//Functions

	void collision();
	void updateplayer();
	void updateWorld();
	void updateBullet();

	//void updateCollision();
	void update();
	void renderPlayer();
	void renderWorld();
	void render();
	const sf::RenderWindow& getWindow() const;
};