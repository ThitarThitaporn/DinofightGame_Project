#pragma once
#include"stdafx.h"
#include"Endgame.h"

class Endgame
{

private:

	sf::Font font;
	sf::Text egText;

	sf::Texture egTex;
	sf::Sprite egSprite;


public:
	Endgame(float width, float height);

	~Endgame();
	

	//functions
	void initBoard();
	void render(sf::RenderWindow& window);
	




};

