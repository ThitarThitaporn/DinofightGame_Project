#include"stdafx.h"
#include "Game.h"
#include"Enemy.h"
#include"Bullet.h"
#include"Menu.h"
#include"Endgame.h"
#include"score.h"
#include"Monster.h"



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
void Game::initSound()
{
	buffer[0].loadFromFile("Sound/gameRun.wav");
	sound[0].setBuffer(buffer[0]);

	buffer[1].loadFromFile("Sound/open.wav");
	sound[1].setBuffer(buffer[1]);

	buffer[2].loadFromFile("Sound/sound_over.wav");
	sound[2].setBuffer(buffer[2]);

	buffer[3].loadFromFile("Sound/bullet.wav");
	sound[3].setBuffer(buffer[3]);
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

void Game::initMonster()
{
	this->monster = new Monster();
}

void Game::initFoeman()
{
	this->foeman = new Foeman();
}

void Game::initHpBar()
{
	this->hpBar = new PlayerGUI();
}

void Game::initGUI()
{
	this->playerGUI = new PlayerGUI();
}


void Game::initUsername()
{
	if (!this->nameBackgroundTex.loadFromFile("texTure/entername.png"))
	{
		std::cout << "ERORR Can't load background" << "\n";
	}
	this->nameBackground.setTexture(this->nameBackgroundTex);
	this->nameBackground.setScale(0.83f, 0.912f);
}

void Game::initGameover()
{
	this->gameOver = new Endgame();
}

Game::Game()
{
	timeUS = timeText.getElapsedTime().asMilliseconds();
	end = 0;
	this->initWindow();
	this->initSound();
	this->initUsername();
	this->initplayer();
	this->initWorld();
	this->initBullet();
	this->initEnemy();
	this->initMonster();
	this->initFoeman();
	this->initGUI();
	this->initHpBar();
	this->initGameover();
	//this->scoreboard.wFile();

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

	//Delete monster
	for (auto* i : this->monsterP)
	{
		delete i;
	}

	//Delete Foeman
	for (auto* i : this->foemans)
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
	//Shield
	for (auto* i : this->shield)
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

void Game::updateSong()
{
	if (GameRun == false && ThemeSongOn == false)
	{
		ThemeSongOn = true;
		
		sound[0].play();
		sound[0].setVolume(4);
	///*	sound[1].play();
	//	sound[1].setVolume(2);*/
	//	//ThemeSongOn = false;
	}

	/*if ( Gameovercheck== true && GameOverSong == true)
	{
		
		GameOverSong = false;
	}*/
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
			this->playerGUI->setHp(20);

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

void Game::updateShield()
{
	if (this->playerGUI->hp <= 80)
	{
		if (this->randomShield.getElapsedTime().asSeconds() >= 12.f)
		{
			if (countShield < 1)
			{
				shieldX = 70 + rand() % 1500;
				shieldY = 100 + rand() % 450;
				this->shield.push_back(new Shield(shieldX, shieldY));
				this->randomShield.restart();
				countShield++;
			}

		}

	}
	//Update
	for (int i = 0; i < this->shield.size(); ++i)
	{
		this->shield[i]->update();
	}

	//Collision
	for (size_t i = 0; i < this->shield.size(); i++)
	{
		if (this->player->getBoundsHitbox().intersects(this->shield[i]->getGlobalBoundsHitbox())
			&& this->delayShield.getElapsedTime().asSeconds() > 0.5f && this->playerGUI->hp >= 0)
		{
			//Do not decrease Hp
			this->playerGUI->setHp(0);
			IsAura = true;
			IsStart = true;

			//Delete Shield
			this->shield.erase(this->shield.begin() + i);
			countShield--;

			this->delayShield.restart();
			this->delayAura.restart();
			break;

		}
		/*else
		{
			IsAura = false;
			IsStart = false;
		}*/

		//Left of screen
		if (this->shield[i]->getPosition().x + this->shield[i]->getGlobalbounds().width < 0)
		{
			this->shield.erase(this->shield.begin() + i);
			countShield--;
			break;
		}

		//Draw Aura 
		if (IsAura == true)
		{
			this->shield[i]->setPositionAura(this->player->getPosition().x - 40.f, this->player->getPosition().y + 25.f);
		}

		if (delayAura.getElapsedTime().asSeconds() >= 3.f)
			IsAura = false;

	}

}

void Game::updateChest()
{

	unsigned countChest = 0;
		
	
	if (this->playerGUI->score >= 300 && this->playerGUI->score <= 600)
	{

		if (this->randChest.getElapsedTime().asSeconds() >= 10.f)
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

	if (this->playerGUI->score >= 800 && this->playerGUI->score <= 1000)
	{

		if (this->randChest.getElapsedTime().asSeconds() >= 9.f)
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
	if (this->playerGUI->score >= 1100)
	{

		if (this->randChest.getElapsedTime().asSeconds() >= 9.f)
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
			
			this->playerGUI->setScore(50);

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


	if (this->playerGUI->score >= 200 && this->playerGUI->score <= 500)
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
	if (this->playerGUI->score >= 700 && this->playerGUI->score <=1000 )
	{

		//if (this->randStone.getElapsedTime().asSeconds() >= 4.f)
		//{
		if (countStone < 1)
		{
			StoneX += 950.f;
			this->stone.push_back(new Stone(StoneX, 780));

		}
		//}

	}
	if (this->playerGUI->score >=  1200)
	{

		//if (this->randStone.getElapsedTime().asSeconds() >= 4.f)
		//{
		if (countStone < 1)
		{
			StoneX += 950.f;
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
			&& this->timeStone.getElapsedTime().asSeconds() > 1.f && this->playerGUI->hp >= 10 && this->delayAura.getElapsedTime().asSeconds() >= 5.f)
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
	//level 1
	if (enemiseCount < 5 && this->playerGUI->score <=200)
	{
		//printf("1\n");
		this->enemys.push_back(new Enemy((rand() % 200)+ 1500, (rand() % 500))); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		enemiseCount++;
	}

	//level 2
	if (enemiseCount < 7 && this->playerGUI->score <= 400 && this->playerGUI->score >= 200 )
	{
		//printf("1\n");
		this->enemys.push_back(new Enemy((rand() % 200) + 1500, (rand() % 500))); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		enemiseCount++;
	}

	//level 3
	if (enemiseCount < 9 && this->playerGUI->score <= 400 && this->playerGUI->score >= 600)
	{
		//printf("1\n");
		this->enemys.push_back(new Enemy((rand() % 200) + 1500, (rand() % 500))); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		enemiseCount++;
	}

	//level 4
	if (enemiseCount < 11 && this->playerGUI->score <= 600 && this->playerGUI->score >= 800 )
	{
		//printf("1\n");
		this->enemys.push_back(new Enemy((rand() % 200) + 1500, (rand() % 500))); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		enemiseCount++;
	}

	//level 5
	if (enemiseCount < 4 && this->playerGUI->score >= 1000)
	{
		//printf("1\n");
		this->enemys.push_back(new Enemy((rand() % 200) + 1500, (rand() % 500))); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		enemiseCount++;
	}

	for (int i = 0; i < enemys.size(); ++i) 
	{
		
		this->enemys[i]->update();
		//left sceen
		if (this->enemys[i]->getPosition().x < 0)
		{
			
			this->enemys.erase(this->enemys.begin() + i);
			//this->playerGUI->setScore(-10);
			enemiseCount--;
			break;
		}

			//player collision with enemies
			if (this->player->getBoundsHitbox().intersects(this->enemys[i]->getBoundsHitbox())
				&& this->enemiesTime.getElapsedTime().asSeconds() >= 1.f && this->playerGUI->hp >= 5 && this->delayAura.getElapsedTime().asSeconds() >= 5.f)
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
				this->playerGUI->setScore(10);
				enemiseCount--;
				
				//printf("DD");
				break;
			}

		}

		
		
	}
}

void Game::updateMonster()
{
	if (monsterCount < 1 && this->playerGUI->score <= 800 && this->playerGUI->score >= 600)
	{
		//printf("1\n");
		MonsterX += 1300.f;
		this->monsterP.push_back(new Monster(1200, 450)); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		monsterCount++;
	}

	if (monsterCount < 3 && this->playerGUI->score <= 800 && this->playerGUI->score >= 1000)
	{
		//printf("1\n");
		MonsterX += 1000.f;
		this->monsterP.push_back(new Monster(1200, 450)); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		monsterCount++;
	}
	if (monsterCount < 5 && this->playerGUI->score >= 1500)
	{
		//printf("1\n");
		MonsterX += 1000.f;
		this->monsterP.push_back(new Monster(1200, 450)); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		monsterCount++;
	}
	for (int i = 0; i < monsterP.size(); ++i)
	{

		this->monsterP[i]->update();
		//left sceen
		if (this->monsterP[i]->getPosition().x < 0)
		{

			this->monsterP.erase(this->monsterP.begin() + i);
			//this->playerGUI->setScore(-10);
			monsterCount--;
			break;
		}

		//player collision with enemies
		if (this->player->getBoundsHitbox().intersects(this->monsterP[i]->getBoundsHitbox())
			&& this->monsterTime.getElapsedTime().asSeconds() >= 1.f && this->playerGUI->hp >= 5 && this->delayAura.getElapsedTime().asSeconds() >= 5.f)
		{
			//printf("hp = %d\n", this->playerGUI->hp);
			this->playerGUI->setHp(-5);
			this->monsterTime.restart();

			this->monsterP.erase(this->monsterP.begin() + i);
			monsterCount--;
			break;
		}

		for (int j = 0; j < bullets.size(); ++j)
		{
			if (this->bullets[j]->getBoundsHitbox().intersects(this->monsterP[i]->getBoundsHitbox()))
			{
				/*delete enemy;*/
				this->bullets.erase(bullets.begin() + j);
				this->monsterP[i]->setHP(-1);
				if (this->monsterP[i]->hp == 0)
				{
					this->monsterP.erase(monsterP.begin() + i);
					this->playerGUI->setScore(20);
					monsterCount--;
				}

				//printf("DD");
				break;
			}

		}



	}
}

void Game::updateFoeman()
{
	
	
	if (foemanCount < 2 && this->playerGUI->score <= 800 && this->playerGUI->score >= 20)
	{
		printf("foeman");
		//FoemanX += 1300.f;
		this->foemans.push_back(new Foeman(850, 425)); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		foemanCount++;
	}

	if (foemanCount < 3 && this->playerGUI->score <= 800 && this->playerGUI->score >= 1000)
	{
		//printf("1\n");
		FoemanX += 1100.f;
		this->foemans.push_back(new Foeman(1200, 650)); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		foemanCount++;
	}
	if (foemanCount < 5 && this->playerGUI->score >= 1500)
	{
		//printf("1\n");
		FoemanX += 1100.f;
		this->foemans.push_back(new Foeman(1200, 650)); // ใส่ในอัพเดท เเล้วค่อยใส่เรนดอมเวลา
		foemanCount++;
	}
	for (int i = 0; i < foemans.size(); ++i)
	{
		//this->foemans[i]->updateMovement(this->player->getPos().x, this->player->getPos().y);

		this->foemans[i]->update();
		//left sceen
		if (this->foemans[i]->getPosition().x < 0)
		{

			this->foemans.erase(this->foemans.begin() + i);
			//this->playerGUI->setScore(-10);
			foemanCount--;
			break;
		}

		//player collision with enemies
		if (this->player->getBoundsHitbox().intersects(this->foemans[i]->getBoundsHitbox())
			&& this->foemanTime.getElapsedTime().asSeconds() >= 1.f && this->playerGUI->hp >= 5 && this->delayAura.getElapsedTime().asSeconds() >= 5.f)
		{
			//printf("hp = %d\n", this->playerGUI->hp);
			this->playerGUI->setHp(-10);
			this->foemanTime.restart();

			this->foemans.erase(this->foemans.begin() + i);
			foemanCount--;
			break;
		}

		for (int j = 0; j < bullets.size(); ++j)
		{
			if (this->bullets[j]->getBoundsHitbox().intersects(this->foemans[i]->getBoundsHitbox()))
			{
				/*delete enemy;*/
				this->bullets.erase(bullets.begin() + j);
					this->foemans.erase(foemans.begin() + i);
					this->playerGUI->setScore(15);
					foemanCount--;
				

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

		this->updateSong();
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O) && (bulletTime.getElapsedTime().asSeconds() > 0.5f)) //shoot
		{
			sound[3].play();
			sound[3].setVolume(4);
			this->bullets.push_back(new Bullet(this->player->getPos().x, this->player->getPos().y, 1.f, 0.f, 5.f));
			this->bulletTime.restart();
			//printf("bulletsize %d\n",bullets.size());
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			menuPlay = true;
			GameRun = false;
		}

		if (GameRun == false)
		{
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
					case 0:
						printf("Player has been pressed");
						//go to state

						namestate = true;
						scoreCheck = false;
						menuPlay = false;
						//
						break;

					case 1:
						//go to state
						namestate = false;
						scoreCheck = true;
						menuPlay = false;

						break;

					case 2:
						window.close();
						break;
					}

				}
				break;

			}
		}
	}
	if (GameRun == true && playerGUI->hp > 0)
		{
			this->updateSong();
			this->player->update();
			this->updateBullets();
			this->updateplayer();
			this->updateEnemy();
			this->updateMonster();
			this->updateFoeman();
			this->collision();
			this->updateHpBar();
			this->updateHeartItem();
			this->updateShield();
			this->updateChest();
			this->updateStone();
			this->updateWorld();
		}

	}

	



void Game::renderUsername()	
{

	std::stringstream ss;
	player_name = "";
	sf::Text p_name, menuPress;
	sf::Font font, font2;

	font.loadFromFile("font/dinosaurtext2.ttf");
	font2.loadFromFile("font/rainyhearts.ttf");
	sf::Text enter("Player name", font, 90);
	enter.setFillColor(sf::Color::Black);
	enter.setPosition(610, 210);
	p_name.setFont(font);
	for (int i = 0; i < username.size(); i++)
	{
		player_name += username[i];
	}
	p_name.setCharacterSize(60);
	if (username.empty())
	{
		p_name.setFillColor(sf::Color::Transparent);
		p_name.setString("_");
	}
	else
	{
		ss << player_name << "_";
		std::string str = ss.str();
		p_name.setString(str);
		p_name.setFillColor(sf::Color::Black);
	}
	p_name.setPosition(860 - (p_name.getGlobalBounds().width / 2), 480);
	sf::Text Enterplay("Press \"Enter\" to continue", font2, 40);
	menuPress = Enterplay;
	menuPress.setFillColor(sf::Color::Black);
	menuPress.setOrigin(sf::Vector2f(menuPress.getGlobalBounds().width / 2, 0));
	menuPress.setPosition(sf::Vector2f(850, 650));
	window.draw(p_name);
	window.draw(enter);
	window.draw(menuPress);
	


}

void Game::renderNamebg()
{
	this->window.draw(this->nameBackground);
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

void Game::renderShield()
{
	for (auto* i : this->shield)
	{
		i->render(this->window);

		if (IsAura == true)
			i->renderAura(this->window);
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

void Game::renderMonster()
{
	this->monster->render(this->window);
}

void Game::renderFoeman()
{
	this->foeman->render(this->window);
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
	this->scoreboard.renderScoreBackground(this->window);
	this->scoreboard.Drawscore(this->window);
}

void Game::renderGameover()
{
	this->gameOver->render(window);
}

void Game::render()
{
	this->window.clear();

	timeUS = timeText.getElapsedTime().asMilliseconds();
	

	if (namestate) {


		if (ev.type == sf::Event::TextEntered && timeUS > 500) {

			timeText.restart();
			username.push_back(ev.text.unicode);
		}
		if (!username.empty() && username.back() == 8)
		{
			username.pop_back();
			if (!username.empty())
				username.pop_back();
		}
		if (username.size() != 1 && !username.empty() && username.back() == 13)
		{
			username.pop_back();
		}
		if (!username.empty() && !((username.back() >= 'A' && username.back() <= 'Z') || (username.back() >= 'a' && username.back() <= 'z') || (username.back() >= '0' && username.back() <= '9') || username.back() == '_'))
		{
			username.pop_back();
		}
		if (username.size() > 15)
		{
			username.pop_back();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && username.size() != 0) 
		{

			this->getName(player_name);
			//namestate = true;
			namestate = false;
			//printf("Enter");
			GameRun = true;
			std::cout << player_name;
		}


	}
	

	
	if (GameRun == true )
	{
		
		//draw wolrd
		this->renderWorld();
		//render game
		this->renderShield();
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

		//render monster
		this->renderMonster();
		for (auto* monster : this->monsterP)
		{
			monster->render(this->window);
		}

		//render foeman
		this->renderFoeman();
		for (auto* foeman : this->foemans)
		{
			foeman->render(this->window);
		}


		this->renderGUI();
	
		//render ITEM
		this->renderHeartItem();
		this->renderChest();
		

		//render Stone
		this->renderStone();

		//render Gameover
		if (this->playerGUI->hp <= 0 )
		{
			this->scoreboard.scoreplayer = playerGUI->score ;
			
			if (end < 1)
			{

				sound[2].play();
				sound[2].setVolume(5);
				this->scoreboard.wFile();
				end++;
			}
			this->renderGameover();
			Gameovercheck = true;
			GameOverSong = true;
			//this->renderSavescore();
		}
		
	}

	else 
	{
		//this->endGame->render(window);
		if (menuPlay == true)
		{
		this->menu->render(window);
		}
		
		else
		{
			if (namestate)
			{
			
				this->renderNamebg();
				this->renderUsername();

			}

			if (scoreCheck == true)
			{
				this->renderSavescore();
			}

		}

	}

	this->window.display();

}

const sf::RenderWindow& Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}
