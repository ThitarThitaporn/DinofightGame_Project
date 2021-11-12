#include "stdafx.h"
#include "Chest.h"

void Chest::initHitbox()
{
    this->chestHitbox.setOutlineColor(sf::Color::Blue);
    this->chestHitbox.setOutlineThickness(2.f);
    this->chestHitbox.setFillColor(sf::Color::Transparent);
    this->chestHitbox.setSize(sf::Vector2f(140.f, 140.f));

}

void Chest::initSprite()
{
    if (!this->chestTex.loadFromFile("texTure/chest.png"))
    {
        std::cout << "ERROR::PLAYER::Could not load the boostHp sheet!" << "\n";
    }
}

void Chest::initTexture()
{
    this->chestSprite.setTexture(this->chestTex);
    this->chestSprite.setScale(1.25f, 1.25f);
}

void Chest::updateHitbox()
{
    this->chestHitbox.setPosition(chestSprite.getPosition().x + 40.f , chestSprite.getPosition().y + 40); 
}

void Chest::updateMovement()
{
    this->chestSprite.setPosition(chestX, this->chestSprite.getPosition().y);
    chestX--;
}

Chest::~Chest()
{


}

Chest::Chest(float x, float y)
{

    this->initSprite();
    this->initHitbox();
    this->initTexture();
    this->setPosition(x, y);

    chestX = x;

}

const sf::Vector2f Chest::getPosition()
{
    return this->chestSprite.getPosition();
}

const sf::FloatRect Chest::getBounds() const
{
    return this->chestSprite.getGlobalBounds();
}

void Chest::setPosition(float x, float y)
{
    this->chestSprite.setPosition(x, y);
}

const sf::FloatRect Chest::getBoundsHitbox()
{
    return this->chestHitbox.getGlobalBounds();
}

void Chest::update()
{
    this->updateMovement();
    this->updateHitbox();
}

void Chest::render(sf::RenderTarget& target)
{

    target.draw(this->chestSprite);
    target.draw(this->chestHitbox);

}
