#include "stdafx.h"
#include "PlayerGUI.h"

void PlayerGUI::initFont()
{
	if (!this->font.loadFromFile("font/dinosaurtext2.ttf"))
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
	this->scoreTex.setPosition(1440.f, 10.f);

}
void PlayerGUI::initLevelBar()
{
	this->levelTex.setFont(this->font);
	this->levelTex.setFillColor(sf::Color::Black);
	this->levelTex.setCharacterSize(40.f);
	this->levelTex.setPosition(1180.f, 10.f);
}
//void Game::initLevel()
//{
//	std::stringstream ss;
//	ss << "Level :" << level;
//	std::string str = ss.str();
//	Level.setString(str);
//
//	Level.setString("LEVEL : 0");
//	Level.setPosition(50, 60);
//	Level.setFillColor(sf::Color::White);
//}

PlayerGUI::PlayerGUI()
{
	this->initFont();
	this->initHpBar();
	this->initScoreBar();
	this->initLevelBar();

	this->hp;
	this->score;
	this->level;

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

void PlayerGUI::setLevel(int n)
{
	this->level = n;
}

void PlayerGUI::updateScore()
{
	this->scoreString = "Score : " + std::to_string(this->score);
	this->scoreTex.setString(this->scoreString);
}

void PlayerGUI::updateHpBar()
{

	this->hpBarInner.setSize(sf::Vector2f(this->hp * 3, this->hpBarInner.getSize().y));
	this->hpBarString = std::to_string(this->hp) + " / " + std::to_string(100);
	this->hpBarText.setString(this->hpBarString);

	
}

void PlayerGUI::updatLevel()
{
	this->levelString = "Level : " + std::to_string(this->level);
	this->levelTex.setString(this->levelString);

	if (this->score >= 200 && this->score <= 400)
	{
		this->setLevel(1);
	}
	else if (this->score >= 400 && this->score <= 600)
	{
		this->setLevel(2);
	}
	else if (this->score >= 600 && this->score <= 800)
	{
		this->setLevel(3);
	}
	else if (this->score >= 800 && this->score <= 1000)
	{
		this->setLevel(4);
	}
	
	else if(this->score >= 1000)
	{
		this->setLevel(5);
	}
	
}

void PlayerGUI::update()
{
	this->updateHpBar();
	this->updateScore();
	this->updatLevel();
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

void PlayerGUI::renderLevel(sf::RenderTarget& target)
{
	target.draw(this->levelTex);
}

void PlayerGUI::render(sf::RenderTarget& target)
{
	this->renderHpBar(target);
	this->renderScore(target);
	this->renderLevel(target);
}
