#include "stdafx.h"
#include "Stone.h"

void Stone::initHitbox()
{
	stoneHitbox.setOutlineColor(sf::Color::Blue);
	stoneHitbox.setOutlineThickness(2.f);
	stoneHitbox.setFillColor(sf::Color::Transparent);
	stoneHitbox.setSize(sf::Vector2f(140.f, 128.f));
}

void Stone::initSprite()

{
	if (!this->stoneTex.loadFromFile("texTure/stone.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the stone sheet!" << "\n";
	}
	
	
}

void Stone::initTexture()
{
	this->stoneSprite.setTexture(this->stoneTex);
	this->stoneSprite.setScale(0.4f, 0.4f);
}

Stone::~Stone()
{
}

Stone::Stone(float x, float y)
{
	this->initSprite();
	this->initHitbox();
	this->initTexture();
	this->setPosition(x, y);
	StoneX = x;
}

const sf::Vector2f Stone::getPosition()
{
	return this->stoneSprite.getPosition();
}

const sf::FloatRect Stone::getGlobalbounds()
{
	return this->stoneSprite.getGlobalBounds();
}

void Stone::setPosition(float x, float y)
{
	this->stoneSprite.setPosition(x, y);
}

const sf::FloatRect Stone::getGlobalBoundsHitbox() const
{
	return this->stoneHitbox.getGlobalBounds();
}

void Stone::update()
{
	this->updateHitbox();
	this->updateMovement();
}

void Stone::updateHitbox()
{
	stoneHitbox.setPosition(stoneSprite.getPosition().x, stoneSprite.getPosition().y);
}

void Stone::updateMovement()
{
	this->stoneSprite.setPosition(StoneX, this->stoneSprite.getPosition().y);
	this->stoneSprite.setRotation(30.f);
	StoneX -= 2;
}

void Stone::render(sf::RenderTarget& target)
{
	//target.draw(this->stoneHitbox);
	target.draw(this->stoneSprite);
}
