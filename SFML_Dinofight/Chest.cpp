#include "stdafx.h"
#include "Chest.h"

void Chest::initHitbox()
{
    this->chestHitbox.setOutlineColor(sf::Color::Blue);
    this->chestHitbox.setOutlineThickness(2.f);
    this->chestHitbox.setFillColor(sf::Color::Transparent);
    this->chestHitbox.setSize(sf::Vector2f(50.f, 50.f));

}

void Chest::initSprite()
{
    if (!this->chestTex.loadFromFile("texTure/itemHeart1.jpg"))
    {
        std::cout << "ERROR::PLAYER::Could not load the boostHp sheet!" << "\n";
    }
}

void Chest::initTexture()
{
    this->chestSprite.setTexture(this->chestTex);
    this->chestSprite.setScale(2.f, 2.f);
}

void Chest::updateHitbox()
{
    this->chestHitbox.setPosition(chestSprite.getPosition().x + 2.5f, chestSprite.getPosition().y + 2.f);
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

    this->initHitbox();
    this->initTexture();
    this->initSprite();
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
