#include "stdafx.h"
#include "Menu.h"

void Menu::initHitbox()
{
	this->MynameHitbox.setOutlineColor(sf::Color::White);
	this->MynameHitbox.setOutlineThickness(5.f);
	this->MynameHitbox.setFillColor(sf::Color::Black);
	this->MynameHitbox.setSize(sf::Vector2f(560.f, 82.f));
	this->MynameHitbox.setPosition(25, 25);
}

Menu::Menu(float width, float height)
{
	if (!this->font.loadFromFile("font/dinosaurtext2.ttf"))
	{
		std::cout << "ERROR::MENU::Could not load the Font sheet!" << "\n";
	}

	if (!this->font2.loadFromFile("font/dinosaur1.ttf"))
	{
		std::cout << "ERROR::MENU::Could not load the Font sheet!" << "\n";
	}

	if (!this->menuTex.loadFromFile("texTure/background1.jpg"))
	{
		std::cout << "ERROR" << "\n";
	}

	this->initBackground();
	this->initHitbox();
	myName.setFont(font);
	myName.setCharacterSize(35);
	myName.setFillColor(sf::Color::White);
	myName.setString("64011100 Thitaporn Longji");
	myName.setOrigin(myName.getLocalBounds().width / 2, myName.getLocalBounds().height / 2);
	myName.setPosition(300, 60);

	menu[0].setFont(font);
	menu[0].setCharacterSize(110);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setCharacterSize(80);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("LeaderBoard");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setCharacterSize(80);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));



}


Menu::~Menu()
{

}

int Menu::getPressedItem()
{
	return selectedItem;
}

void Menu::initBackground()
{
	this->menuSprite.setTexture(menuTex);
}

void Menu::render(sf::RenderWindow& window)
{
	window.draw(menuSprite);
	window.draw(MynameHitbox);
	window.draw(myName);
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		window.draw(menu[i]);
		//printf("Render");
	}
}

void Menu::moveUp()
{
	if (selectedItem - 1 >= 0)
	{
		
		menu[selectedItem].setFillColor(sf::Color::White);
			selectedItem-- ;
			menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (selectedItem < MAX_ITEMS - 1  )
	{
	//	printf("%d", this->selectedItem);
		menu[selectedItem].setFillColor(sf::Color::White);
			selectedItem++ ;
			menu[selectedItem].setFillColor(sf::Color::Red);
	}
}
