#include "stdafx.h"
#include "HeartItem.h"

void HeartItem::initHitbox()
{
	this->heartHitbox.setOutlineColor(sf::Color::Blue);
	this->heartHitbox.setOutlineThickness(2.f);
	this->heartHitbox.setFillColor(sf::Color::Transparent);
	this->heartHitbox.setSize(sf::Vector2f(50.f, 50.f));

}

void HeartItem::initTexture()
{
	if (!this->heartTex.loadFromFile("texTure/heartitem1.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the boostHp sheet!" << "\n";
	}
}
void HeartItem::initSprite()
{
	this->heartSprite.setTexture(this->heartTex);
	this->heartSprite.setScale(0.25f, 0.25f);
	
}


void HeartItem::updateHitbox()
{
	this->heartHitbox.setPosition(heartSprite.getPosition().x + 2.5f, heartSprite.getPosition().y + 2.f);
}

void HeartItem::updateMovement()
{

	this->heartSprite.setPosition(heartX, this->heartSprite.getPosition().y);
	heartX--;
}

HeartItem::~HeartItem()
{

}

HeartItem::HeartItem(float x, float y)
{
	this->initHitbox();
	this->initTexture();
	this->initSprite();
	this->setPosition(x, y);

	heartX = x;
}

const sf::Vector2f HeartItem::getPosition()
{
	return this->heartSprite.getPosition();
}

const sf::FloatRect HeartItem::getBounds() const
{
	return this->heartSprite.getGlobalBounds();
}

void HeartItem::setPosition(float x, float y)
{
	this->heartSprite.setPosition( x,  y);
}

const sf::FloatRect HeartItem::getBoundsHitbox()
{
	return this->heartHitbox.getGlobalBounds();
}

void HeartItem::update()
{
	this->updateMovement();
	this->updateHitbox();
}

void HeartItem::render(sf::RenderTarget& target)
{
	target.draw(this->heartSprite);
	//target.draw(this->heartHitbox);
}

