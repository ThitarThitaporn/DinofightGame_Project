#pragma once
#include<map>
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

	//Resources
	std::map<std::string,sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	Player* player;
	Bullet* bullet;
	

	void initWindow();
	void initplayer();
	void initBullet();
	
	void initWorld();



public:

	//Functions
	Game();
	virtual ~Game();
	//Functions

	void collision();
	void updateBullets();
	void updateplayer();
	/*void updateBullet();*/
	void updateWorld();
	

	//void updateCollision();
	void update();
	void renderPlayer();
	void renderBullet();
	void renderWorld();
	void render();
	const sf::RenderWindow& getWindow() const;
};