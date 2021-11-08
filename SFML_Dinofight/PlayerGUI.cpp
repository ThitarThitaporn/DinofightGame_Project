#include "stdafx.h"
#include "PlayerGUI.h"

void PlayerGUI::initFont()
{
	if (!this->font.loadFromFile("font/dinosaur1.ttf"))
		std::cout << "ERROR::PLAYERGUI::Could not load the Font sheet!" << "\n";
}

void PlayerGUI::initHpBar()
{
	float width = 300.f;
	float height = 40.f;
	float x = 20.f;
	float y = 20.f;

	this->hpBarMaxwidth = width;

	this->hpBarBack.setSize(sf::Vector2f(width, height));
	this->hpBarBack.setFillColor(sf::Color(50, 50, 50, 200));
	this->hpBarBack.setPosition(x, y);

	this->hpBarInner.setSize(sf::Vector2f(width, height));
	this->hpBarInner.setFillColor(sf::Color(250, 20, 20, 200));
	this->hpBarInner.setPosition(this->hpBarBack.getPosition());

	this->hpBarText.setFont(this->font);
	this->hpBarText.setPosition(this->hpBarInner.getPosition().x + 20.f, this->hpBarInner.getPosition().y);

}

void PlayerGUI::initScoreBar()
{
	this->scoreTex.setFont(this->font);
	this->scoreTex.setFillColor(sf::Color::Black);
	this->scoreTex.setCharacterSize(40.f);
	this->scoreTex.setPosition(1400.f, 10.f);

}

PlayerGUI::PlayerGUI()
{
	this->initFont();
	this->initHpBar();
	this->initScoreBar();

	this->hp;
	this->score;

}

PlayerGUI::~PlayerGUI()
{

}

//Function
void PlayerGUI::setScore(int n)
{
	this->score += n;

}

void PlayerGUI::setHp(int n)
{
	if (this->hp >= 0)
		this->hp += n;
}

void PlayerGUI::updateScore()
{
	this->scoreString = "score : " + std::to_string(this->score);
	this->scoreTex.setString(this->scoreString);
}

void PlayerGUI::updateHpBar()
{

	this->hpBarInner.setSize(sf::Vector2f(this->hp * 3, this->hpBarInner.getSize().y));
	this->hpBarString = std::to_string(this->hp) + " / " + std::to_string(100);
	this->hpBarText.setString(this->hpBarString);
}

void PlayerGUI::update()
{
	this->updateHpBar();
	this->updateScore();
}

void PlayerGUI::renderScore(sf::RenderTarget& target)
{
	target.draw(this->scoreTex);
}

void PlayerGUI::renderHpBar(sf::RenderTarget& target)
{
	target.draw(this->hpBarBack);
	target.draw(this->hpBarInner);
	target.draw(this->hpBarText);
}

void PlayerGUI::render(sf::RenderTarget& target)
{
	this->renderHpBar(target);
	this->renderScore(target);
}
