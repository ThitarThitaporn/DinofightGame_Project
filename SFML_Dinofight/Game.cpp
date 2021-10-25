#include"stdafx.h"
#include "Game.h"
void Game::initWindow()
{
	this->window.create(sf::VideoMode(1700, 850), "GAME Dino", sf::Style::Close | sf::Style::Titlebar, sf::ContextSettings());
	this->window.setFramerateLimit(60);

}
void Game::initplayer()
{
	this->player = new Player();
}
void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("texTure/bg2.jpg"))
	{
		std::cout << "Error" << "\n";

	}
	this->worldBackground.setTexture(this->worldBackgroundTex);
	this->worldBackground.setScale(0.5f,0.72f);
	

}
Game::Game()

{
	this->initWindow();
	this->initplayer();
	this->initWorld();
}

Game::~Game()
{
	delete this->player;
}

void Game::collision()
{
	if (this->player->getPosition().y + this->player->getGlobalBouds().height  >  this-> window.getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(this->player->getPosition().x, this->window.getSize().y - this->player->getGlobalBouds().height);
		this->player->jumping = false;
		this->player->jumpingup = false;
		this->player->gravityBool = false;
	}
}

void Game::updateplayer()
{
	this->player->update();
}

void Game::updateWorld()
{
	this->worldBackground.setPosition(backgroundX, this->worldBackground.getPosition().y);
	this->backgroundX -= 0.6; 
}

//void Game::updateCollision()
//{
//	//collision bottom of screen
//	if (this->player->getGlobalBouds().top + this->player->getGlobalBouds().height > this->window.getSize().y);
//	{
//		this->player->resetVelocityY();
//		this->player->setPosition
//		(
//			this->player->getGlobalBouds().left,
//			this->window.getSize().y - this->player->getGlobalBouds().height
//		);
//	}
//
//}

void Game::update()
{
	//polling window event
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();

		if (this->ev.type == sf::Event::KeyReleased &&
			(
				this->ev.key.code == sf::Keyboard::A ||
				this->ev.key.code == sf::Keyboard::D ||
				this->ev.key.code == sf::Keyboard::W ||
				this->ev.key.code == sf::Keyboard::S
				)
			)
			this->player->resetAnimationTimer();
	}
	this->updateplayer();
	this->collision();
	this->updateWorld();

	//this->updateCollision();

}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::renderWorld()
{
	this->window.draw(this->worldBackground);
}

void Game::render()
{
	this->window.clear();

	//draw wolrd
	this->renderWorld();

	//render game
	this->renderPlayer();
	this->window.display();

}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}