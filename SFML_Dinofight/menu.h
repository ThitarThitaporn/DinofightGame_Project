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


public:
	Menu(float width,float height);

		~Menu();

	//functions
		void draw(sf::RenderWindow& window);
		void moveUp();
		void moveDown();



};

