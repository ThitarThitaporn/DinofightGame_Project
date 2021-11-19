#pragma once
#include"stdafx.h"
#include"Endgame.h"

class Endgame
{

private:

	sf::Font font;
	sf::Text egText;

	sf::Texture overTex;
	sf::Sprite overSprite;

	//functions
	void initSprite();
	void initTexture();


public:
	Endgame();

	~Endgame();
	
	const sf::Vector2f getPosition();
	void setPosition(float x, float y);
	void update();
	void render(sf::RenderTarget& target);



};






