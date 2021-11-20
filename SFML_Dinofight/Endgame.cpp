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
void Endgame::initFont()
{
    if (!this->font.loadFromFile("font/rainyhearts.ttf"))
        std::cout << "ERROR::PLAYERGUI::Could not load the Font sheet!" << "\n";
}
void Endgame::initMenupress()
{
    
    this->menuPressText.setFont(this->font);
    this->menuPressText.setFillColor(sf::Color::White); //(255, 235, 59, 500)
    this->menuPressText.setCharacterSize(53.f);
    this->menuPressText.setString("Press \"Space Bar\" to exit to mainmenu");
    this->menuPressText.setPosition(1700.f / 2.f - this->menuPressText.getGlobalBounds().width / 2.f, 760.f / 2.f - this->menuPressText.getGlobalBounds().height / 2.f + 200.f);
}
Endgame::Endgame()
{
    this->initSprite();
    this->initTexture();
    this->initFont();
    this->initMenupress();
   
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

void Endgame::renderMenuPress(sf::RenderTarget& target)
{
    target.draw(this->menuPressText);
    //printf("ffffffffff");
   
}



void Endgame::renderSprite(sf::RenderTarget& target)
{
  target.draw(this->overSprite);
}

void Endgame::render(sf::RenderTarget& target)
{
    this->renderMenuPress(target);
    this->renderSprite(target);
}



