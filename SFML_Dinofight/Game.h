#pragma once
#include"stdafx.h"
#include"player.h"
class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;

	Player* player;

	void initWindow();
	void initplayer();


public:

	//Functions
	Game();
	virtual ~Game();
	//Functions

	void updateplayer();
	void updateCollision();
	void update();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getWindow() const;
};