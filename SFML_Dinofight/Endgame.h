#pragma once
#include"stdafx.h"
#include"Endgame.h"

class Endgame
{

private:

	sf::Font font;
	sf::Text menuPressText;
	std::string text;

	sf::Texture overTex;
	sf::Sprite overSprite;

	//functions
	void initSprite();
	void initTexture();
	void initFont();
	void initMenupress();


public:
	Endgame();

	~Endgame();
	
	const sf::Vector2f getPosition();
	void setPosition(float x, float y);
	void update();
	void renderMenuPress(sf::RenderTarget& target);
	void renderSprite(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);



};






