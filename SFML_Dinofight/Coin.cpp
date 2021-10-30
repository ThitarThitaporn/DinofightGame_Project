#include "stdafx.h"
#include "Coin.h"

void Coin::initSprite()
{

}

void Coin::initTextures()
{
	if (!this->coinTex.loadFromFile("texTure/playerdinoall.png"))
	{
		std::cout << "ERROR" << "\n";
	}
}

Coin::~Coin()
{
}

const sf::Vector2f Coin::getPos()
{
	return this->getPos();
}

const sf::FloatRect Coin::getGlobalbonds()
{
	return this->getGlobalbonds();
}

void Coin::setPosition(float x, float y)
{
	this->coin.setPosition(x, y);
}

void Coin::update()
{
}

void Coin::render(sf::RenderTarget& target)
{
	//target.draw(this->sprite);
}


