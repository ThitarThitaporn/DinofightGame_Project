#include "stdafx.h"
#include "Foeman.h"


void Foeman::initfoemanTex()
{
	if (!this->foemanTex.loadFromFile("texTure/foeman.png"))
	{
		std::cout << "ERROR" << "\n";
	}
}

void Foeman::initfoemanSprite()
{
	this->foemanSprite.setTexture(this->foemanTex);
	this->currentFrame = sf::IntRect(0, 0, 127, 138);
	this->foemanSprite.setTextureRect(this->currentFrame);
	this->foemanSprite.setScale(0.9f, 0.9f);
}


void Foeman::initAnimation()
{
	this->foemanTimer.restart();
}

void Foeman::initHitbox()
{

	this->hitboxfoeman.setOutlineColor(sf::Color::Blue);
	this->hitboxfoeman.setOutlineThickness(2.f);
	this->hitboxfoeman.setFillColor(sf::Color::Transparent);
	this->hitboxfoeman.setSize(sf::Vector2f(150.f, 90.f));
}

void Foeman::updateHitbox()
{
	this->hitboxfoeman.setPosition(hitboxfoeman.getPosition().x + 50, hitboxfoeman.getPosition().y);
}

Foeman::Foeman()
{
	this->initfoemanTex();
}

Foeman::Foeman(float pos_x, float pos_y)
{
	this->initfoemanTex();
	this->initfoemanSprite(); //forget
	this->initAnimation();


	//hitbox
	this->initHitbox();
	this->updateHitbox();
	

	this->foemanSprite.setPosition(pos_x, pos_y);
	this->FoemanX = pos_x;
}

Foeman::~Foeman()
{
}

const sf::FloatRect Foeman::getBounds() const
{
	return this->foemanSprite.getGlobalBounds();
}

const sf::Vector2f Foeman::getPosition() const
{
	return this->foemanSprite.getPosition();
}

const sf::Vector2f Foeman::setPosition(float x, float y) const
{
	return this->foemanSprite, setPosition(x, y);
}

const sf::FloatRect Foeman::getBoundsHitbox() const
{
	return this->foemanSprite.getGlobalBounds();
}

void Foeman::updateMovement()
{
	//printf("updateMM");
	FoemanX -= 1.f;
	this->foemanSprite.setPosition(FoemanX, foemanSprite.getPosition().y);
}

void Foeman::updateAnimation()
{
	if (this->foemanTimer.getElapsedTime().asSeconds() >= 0.5f)
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 127.f;
		if (this->currentFrame.left >= 138.f)
			this->currentFrame.left = 0;
		this->foemanTimer.restart();
		this->foemanSprite.setTextureRect(this->currentFrame);
	}
}


void Foeman::update()
{
	this->updateMovement();
	this->updateAnimation();
	this->updateHitbox();
}

void Foeman::render(sf::RenderTarget& target)
{
	target.draw(this->foemanSprite);
}
