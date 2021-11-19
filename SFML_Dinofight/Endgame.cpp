#include "stdafx.h"
#include "Endgame.h"

void Endgame::initSprite()
{
    if (!this->overTex.loadFromFile("texTure/gameover.png"))
    {
        std::cout << "ERROR::PLAYER::Could not load the boostHp sheet!" << "\n";
    }
}

void Endgame::initTexture()
{
    this->overSprite.setTexture(this->overTex);
    this->overSprite.setScale(1.25f, 1.25f);
}
Endgame::Endgame(float width, float height)
{
    this->initSprite();
    this->initTexture();
    this->setPosition(1700 / 2, 850 / 2);
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



