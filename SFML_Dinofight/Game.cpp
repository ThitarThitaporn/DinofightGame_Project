#include"stdafx.h"
#include "Game.h"
#include"Enemy.h"
#include"Bullet.h"
#include"Menu.h"
#include"Endgame.h"

bool Game::over()
{
	return false;
}

void Game::reset()
{

}

//init
void Game::initWindow()
{
	this->window.create(sf::VideoMode(1700, 850), "GAME Dino", sf::Style::Close | sf::Style::Titlebar, sf::ContextSettings());
	this->window.setFramerateLimit(60);

	//menu
	this->menu = new Menu (window.getSize().x, window.getSize().y);
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
void Game::initBullet()
{
	this->bullet = new Bullet();
}

void Game::initEnemy()
{
	this->enemy = new Enemy();
}

void Game::initHpBar()
{
	this->hpBar = new PlayerGUI();
}

void Game::initGUI()
{
	this->playerGUI = new PlayerGUI();
}

void Game::initGameover()
{
	this->gameOver = new Endgame();
}

Game::Game()
{
	this->initWindow();
	this->initplayer();
	this->initWorld();
	this->initBullet();
	this->initEnemy();
	this->initGUI();
	this->initHpBar();
	this->initGameover();
}

Game::~Game()
{
	delete this->player;
	delete this -> bullet;

	//Delete texteres
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	//Delete bullets
	for (auto* i : this->bullets) 
	{
		delete i;
	}

	//Delete enemies
	for (auto* i : this->enemys)
	{
		delete i;
	}

	//HeartItem
	for (auto* i : this->heartItem)
	{
		delete i;
	}

	//Chest
	for (auto* i : this->chest)
	{
		delete i;
	}

	//Stone
	for (auto* i : this->stone)
	{
		delete i;
	}
}

void Game::run()
{
}

void Game::getName(std::string name)
{
	this->scoreboard.Pname = name;
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

// U P D A T E
void Game::updateHeartItem()
{
	unsigned countHeart  = 0;
	if (this->playerGUI->hp <= 60)
	{
		if (this->randHeart.getElapsedTime().asSeconds() >= 12.f)
		{
			
			if (countHeart < 1)
			{

				heartX = 60 + rand() % 1500;
				heartY = 100 + rand() % 500;
				this->heartItem.push_back(new HeartItem(heartX, heartY));
				this->randHeart.restart();
				countHeart++;
			}
		}
	}


	//Update
	for (int i = 0; i < this->heartItem.size(); ++i)
	{
		this->heartItem[i]->update();
	}

	//Collision
	for (size_t i = 0; i < heartItem.size(); i++)
	{
		if (this->player->getBoundsHitbox().intersects(this->heartItem[i]->getBounds())
			&& this->timeHeart.getElapsedTime().asSeconds() > 0.5f && this->playerGUI->hp <= 80)
		{
			//Boost Hp
			this->playerGUI->setHp(10);

			//Delete heart
			this->heartItem.erase(this->heartItem.begin() + i);
			countHeart--;
			break;

			this->timeHeart.restart();
		}

		//Left of screen
		if (this->heartItem[i]->getPosition().x < 0)
		{
			this->heartItem.erase(this->heartItem.begin() + i);
			countHeart--;
			break;
		}
	}
}

void Game::updateChest()
{

	unsigned countChest = 0;
		
	
	if (this->playerGUI->score >= 200)
	{

	if (this->randChest.getElapsedTime().asSeconds() >= 8.f)
	{
		if (countChest < 1)
		{
			//printf("chest");
			ChestX = 60 + rand() % 1400;
			ChestY = 100 + rand() % 500;
			this->chest.push_back(new Chest(ChestX, ChestY));
			this->randChest.restart();
			countChest++;
		}
	}
	
	}


	//Update
	for (int i = 0; i < this->chest.size(); ++i)
	{
		this->chest[i]->update();
	}

	//Collision
	for (size_t i = 0; i < chest.size(); i++)
	{
		if (this->player->getBoundsHitbox().intersects(this->chest[i]->getBounds())
			&& this->timeChest.getElapsedTime().asSeconds() > 0.5f )
		{
			
			this->playerGUI->setScore(20);

			this->chest.erase(this->chest.begin() + i);
			countChest--;
			break;

			this->timeChest.restart();
		}

		//Left of screen
		if (this->chest[i]->getPosition().x < 0)
		{
			this->chest.erase(this->chest.begin() + i);
			countChest--;
			break;
		}
	}
}

void Game::updateStone()
{
	//Count Stone

	unsigned countStone = 0;


	if (this->playerGUI->score >= 100)
	{

		//if (this->randStone.getElapsedTime().asSeconds() >= 4.f)
		//{
			if (countStone < 1)
			{
				StoneX += 1300.f;
				this->stone.push_back(new Stone(StoneX, 780));
				
			}
		//}

	}


	//Update
	for (int i = 0; i < this->stone.size(); ++i)
	{
		this->stone[i]->update();
	}

	//Collision
	for (size_t i = 0; i < stone.size(); i++)
	{
		if (this->player->getBoundsHitbox().intersects(this->stone[i]->getGlobalbounds())
			&& this->timeStone.getElapsedTime().asSeconds() > 1.f && this->playerGUI->hp >= 10)
		{

			this->playerGUI->setHp(-10);
			this->timeStone.restart();
		}

		//Left of screen
		if (this->stone[i]->getPosition().x + this->stone[i]->getGlobalbounds().width < 0)
		{
			this->stone.erase(this->stone.begin() + i);
			countStone--;
			break;
		}
	}
}



void Game::updateHpBar()
{
	this->playerGUI->update();
	
}



void Game::updateBullets()
{
	unsigned counter = 0;
	for (int j = 0; j < bullets.size(); ++j) //
	{
		bullets[j]->update();

		//Bullet culling (top of screen)
		if (this->bullet->getBoundsHitbox().left + bullet->getBoundsHitbox().width < 0.f)
		{
			//Delete bullet
			delete bullet;
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;
			
		}
		++counter;
		if (this->bullets[j]->getPosition().x > 1680)
		{
			//printf("1232652");
			this->bullets.erase(this->bullets.begin() + j);
			counter--;
			break;
		}

	}
}

void Game::updateEnemy()
{
	
	if (enemiseCount < 7)
	{
		//printf("1\n");
		this->enemys.push_back(new Enemy((rand() % 200)+ 1500, (rand() % 500))); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		enemiseCount++;
	}
	for (int i = 0; i < enemys.size(); ++i) 
	{
		
		this->enemys[i]->update();
		if (this->enemys[i]->getPosition().x < 0)
		{
			
			this->enemys.erase(this->enemys.begin() + i);
			this->playerGUI->setScore(-10);
			enemiseCount--;
			break;
		}

			//player collision with enemies
			if (this->player->getBoundsHitbox().intersects(this->enemys[i]->getBoundsHitbox())
				&& this->enemiesTime.getElapsedTime().asSeconds() >= 1.f && this->playerGUI->hp >= 5)
			{
				//printf("hp = %d\n", this->playerGUI->hp);
				this->playerGUI->setHp(-5);
				this->enemiesTime.restart();

				this->enemys.erase(this->enemys.begin() + i);
				enemiseCount--;
				break;
			}

		for(int j = 0; j < bullets.size(); ++j)
		{
			if (this->bullets[j]->getBoundsHitbox().intersects(this->enemys[i]->getBoundsHitbox()))
			{
				/*delete enemy;*/

				this->bullets.erase(bullets.begin() + j);
				this->enemys.erase(enemys.begin() + i);
				this->playerGUI->setScore(5);
				enemiseCount--;
				
				//printf("DD");
				break;
			}

		}

		
		
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

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O )&& (bulletTime.getElapsedTime().asSeconds() > 0.5f)) //shoot
		{
			this->bullets.push_back(new Bullet(this->player->getPos().x, this->player->getPos().y, 1.f, 0.f, 5.f));
			this->bulletTime.restart();
			//printf("bulletsize %d\n",bullets.size());
		}

		switch (ev.type)
		{
		case sf::Event::KeyReleased:
			switch (ev.key.code)
			{
				case sf::Keyboard::Up:
					this->menu->moveUp();
					break;

				case sf::Keyboard::Down:
					this->menu->moveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu->getPressedItem())
					{
					case 0 :
						//printf("Player has been pressed");
						//go to state
						GameRun = true;
						break;

					case 1 :
						//go to state
						//printf("Leader has been pressed");
						break;

					case 2 :
						window.close();
						break;
					}
					
			}
			break;

		}		
	}
	if (GameRun == true && playerGUI->hp > 0)
		{
			this->player->update();
			this->updateBullets();
			this->updateplayer();
			this->updateEnemy();
			this->collision();
			this->updateHpBar();
			this->updateHeartItem();
			this->updateChest();
			this->updateStone();
			this->updateWorld();
		}

	}

	



// R E N D E R
void Game::renderGUI()
{
	this->playerGUI->render(this->window);
}

void Game::renderHeartItem()
{
	for (auto* i : this->heartItem)
	{
		i->render(this->window);
	}
}

void Game::renderChest()
{
	for (auto* i : this->chest)
	{
		i->render(this->window);
	}
}

void Game::renderStone()
{
	for (auto* i : this->stone)
	{
		i->render(this->window);
	}
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::renderBullet()
{
	this->bullet->render(this->window);
}

void Game::renderEnemy()
{
	this->enemy->render(this->window);
}

void Game::renderEndgame()
{
	this->endGame->render(this->window);
}

void Game::renderWorld()
{
	this->window.draw(this->worldBackground);
}

void Game::renderSavescore()
{
	this->scoreboard.Drawscore(this->window);
}

void Game::renderGameover()
{
	this->gameOver->render(window);
}

void Game::render()
{
	this->window.clear();
	

	if (GameRun == true  )
	{

		//draw wolrd
		this->renderWorld();

		//render game
		this->renderPlayer();


		//render bullet
		this->renderBullet();
			for (auto* bullet : this->bullets)
			{
				bullet->render(this->window);
			}

		//render enemy
		this->renderEnemy();
		for (auto* enemy : this->enemys)
		{		
			enemy->render(this->window);
		}

		this->renderGUI();
	
		//render ITEM
		this->renderHeartItem();

		//render Chest
		this->renderChest();

		//render Stone
		this->renderStone();

		//render Gameover
		if (this->playerGUI->hp <= 0)
		{
			this->renderGameover();
			this->renderSavescore();
		}

		
	}

	else 
	{
		//this->endGame->render(window);
		this->menu->render(window);
	}

	this->window.display();

}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}
