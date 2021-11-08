#pragma once
#include"stdafx.h"
#include"Menu.h"
#define MAX_ITEMS 3
class Menu
{

private:

	int selectedItem = 0;
	sf::Font font;
	sf::Text menu[MAX_ITEMS];

	sf::Texture menuTex;
	sf::Sprite menuSprite;


public:
	Menu(float width,float height);

		~Menu();
		int getPressedItem();

	//functions
		void initBackground();
		void render(sf::RenderWindow& window);
		void moveUp();
		void moveDown();
		



};

