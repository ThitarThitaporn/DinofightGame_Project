#include "stdafx.h"
#include "Endgame.h"


Endgame::Endgame(float width, float height)
{
	if (!this->font.loadFromFile("font/dinosaurtext2.ttf"))
	{
		std::cout << "ERROR::MENU::Could not load the Font sheet!" << "\n";
	}

	if (!this->egTex.loadFromFile("texTure/bg.png"))
	{
		std::cout << "ERROR" << "\n";
	}

	this->initBoard();

	egText.setFont(font);
	egText.setCharacterSize(110);
	egText.setFillColor(sf::Color::Red);
	egText.setString("Play");
	egText.setOrigin(egText.getLocalBounds().width / 2, egText.getLocalBounds().height / 2);
	egText.setPosition(sf::Vector2f(width / 2, height));


}

void Endgame::initBoard()
{
	this->egSprite.setTexture(egTex);
}

void Endgame::render(sf::RenderWindow& window)
{
	window.draw(egSprite);

}
