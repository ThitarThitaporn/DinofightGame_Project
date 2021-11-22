#include "stdafx.h"
#include "Monster.h"

void Monster::initMonsterTex()
{
	if (!this->monsterTex.loadFromFile("texTure/monster2.png"))
	{
		std::cout << "ERROR" << "\n";
	}
}

void Monster::initMonsterSprite()
{
	this->monsterSprite.setTexture(this->monsterTex);
	this->currentFrame = sf::IntRect(0, 0, 273, 221);
	this->monsterSprite.setTextureRect(this->currentFrame);
	this->monsterSprite.setScale(2.f, 2.f);
}

void Monster::initAnimation()
{
	this->monsterTimer.restart();
}

void Monster::initVariables()
{
	
	this->hp = 3;
}

void Monster::initHitbox()
{

	this->hitboxMonster.setOutlineColor(sf::Color::Blue);
	this->hitboxMonster.setOutlineThickness(2.f);
	this->hitboxMonster.setFillColor(sf::Color::Transparent);
	this->hitboxMonster.setSize(sf::Vector2f(150.f, 90.f));
}

void Monster::updateHitbox()
{
	this->hitboxMonster.setPosition(monsterSprite.getPosition().x + 50, monsterSprite.getPosition().y);
}

Monster::Monster()
{
	this->initMonsterTex();
}

Monster::Monster(float pos_x, float pos_y)
{
	this->initMonsterTex();
	this->initMonsterSprite(); //forget
	this->initAnimation();
	this->initVariables();
	

	//hitbox
	this->initHitbox();
	this->updateHitbox();

	this->monsterSprite.setPosition(pos_x, pos_y);
	this->MonsterX = pos_x;
}

Monster::~Monster()
{
}

const sf::FloatRect Monster::getBounds() const
{
	return this->monsterSprite.getGlobalBounds();
}

const sf::Vector2f Monster::getPosition() const
{
	return this->monsterSprite.getPosition();
}

const sf::Vector2f Monster::setPosition(float x, float y) const
{
	return this->monsterSprite, setPosition(x, y);
}

const sf::FloatRect Monster::getBoundsHitbox() const
{
	return this->monsterSprite.getGlobalBounds();
}

void Monster::updateMovement()
{
	MonsterX -= 2;
	this->monsterSprite.setPosition(MonsterX,monsterSprite.getPosition().y);
}

void Monster::updateAnimation()
{
	if (this->monsterTimer.getElapsedTime().asSeconds() >= 0.5f)
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 273.f;
		if (this->currentFrame.left >= 576.f)
			this->currentFrame.left = 0;
		this->monsterTimer.restart();
		this->monsterSprite.setTextureRect(this->currentFrame);
	}
}

void Monster::setHP(int n)
{
	if (hpClock.getElapsedTime().asSeconds() > 0.3f)
	{
		hp--;
		printf("%d", hp);
		this->hpClock.restart();
	}
}


void Monster::update()
{
	this->updateMovement();
	this->updateAnimation();
	this->updateHitbox();
}

void Monster::render(sf::RenderTarget& target)
{
	target.draw(this->monsterSprite);
}
