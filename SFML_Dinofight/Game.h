#pragma once
#include"stdafx.h"
#include"player.h"
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

	void initWindow();
	void initplayer();
	void initWorld();



public:

	//Functions
	Game();
	virtual ~Game();
	//Functions

	void collision();
	void updateplayer();
	void updateWorld();
	//void updateCollision();
	void update();
	void renderPlayer();
	void renderWorld();
	void render();
	const sf::RenderWindow& getWindow() const;
};