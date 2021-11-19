#include "stdafx.h"
#include "Endgame.h"

void Endgame::initSprite()
{
    if (!this->overTex.loadFromFile("texTure/gameover1.png"))
    {
        std::cout << "ERROR::PLAYER::Could not load the boostHp sheet!" << "\n";
    }
}

void Endgame::initTexture()
{
    this->overSprite.setTexture(this->overTex);
    this->overSprite.setScale(1.15f, 1.15f);
    this->overSprite.setPosition(1700.f / 2.f - this->overSprite.getGlobalBounds().width / 2.f, 760.f / 2.f - this->overSprite.getGlobalBounds().height / 2.f);
}
Endgame::Endgame()
{
    this->initSprite();
    this->initTexture();
   
}

Endgame::~Endgame()
{

}


const sf::Vector2f Endgame::getPosition()
{
    return this->overSprite.getPosition();
}

void Endgame::setPosition(float x, float y)
{  

}

void Endgame::update()
{

}

void Endgame::render(sf::RenderTarget& target)
{
  target.draw(this->overSprite);
}



