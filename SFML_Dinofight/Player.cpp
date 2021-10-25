#include "stdafx.h"
#include "Player.h"

void Player::initVariable()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;

}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("texTure/playerdinoall.png"))
	{
		std::cout << "ERROR" << "\n";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(48, 70, 48, 48);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(5.f, 5.f);
}

void Player::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::initPhysics()
{
	this->velocityMax = 10.f;
	this->velocitMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.9f;
	this->gravity = 2.f;
	this->velocityMaxY = 1.f;
}

Player::Player()
{
	this->initVariable();
	this->initTexture();
	this->initSprite();
	this->initAnimation();
	this->initPhysics();
}

Player::~Player()
{

}

const bool& Player::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;
	return anim_switch;

}

const sf::FloatRect Player::getGlobalBouds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}



void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player::resetVelocityX()
{
	this->velocity.x = 0.f;
}

void Player::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::Move(const float dir_x, const float dir_y)
{
	//Acceleration
	this->velocity.x += dir_x * this->acceleration;


	//Limit velocity

	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//jumping 
	if (this->jumping == true && this->gravityBool == false)
	{
		if (this->velocity.y < 0)
		{
			this->jumpingup = false;
		}
		if (this->jumpingup == true)
		{
			this->velocity.y -= 1.f;
		}
		else
		{
			//Gravity
			this->velocity.y += 1.0 * this->gravity;
			if (std::abs(this->velocity.x) > this->velocityMaxY)
				this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
		}
	}

	else
		this->velocity.y += (1.0 * this->gravity);

	if (this->gravityBool == true) 
		this->velocity.y += (1.0 * this->gravity);


	
	if (std::abs(this->velocity.x) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	//Deceleratiion
	this->velocity *= (this->drag);

	//Limit deceleration
	if (std::abs(this->velocity.x) < this->velocitMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocitMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
}

void Player::updateMovement()
{
	this->delayJump = timeJumping.getElapsedTime().asSeconds();
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->sprite.move(-1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->sprite.move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Top
	{
		//this->sprite.move(0.f, -1.f);
		if (delayJump > 0.02f )
		{
			this->jumping = true;
			this->jumpingup = true;
			this->gravityBool = true;
			this->velocity.y = -30.f;
			this->timeJumping.restart();
		}
	

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	{
		this->sprite.move(0.f, 1.f);
	}
	
}

void Player::updatAnimations()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch())
		{
			this->currentFrame.top = 64.f; //gea
			this->currentFrame.left += 48.f;
			if (this->currentFrame.left >= 192.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);

		}
	}

	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 146.f; //gea
			this->currentFrame.left += 48.f;
			if (this->currentFrame.left >= 384.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);

		}
		this->sprite.setScale(5.f, 5.f);
		this->sprite.setOrigin(0.f, 0.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 146.f; //gea
			this->currentFrame.left += 48.f;
			if (this->currentFrame.left >= 384.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);

		}
		this->sprite.setScale(5.f, 5.f);
		/*this->sprite.setOrigin(0.f, 0.f);*/
	}
	
	else
	{
		this->animationTimer.restart();
	}
}

void Player::update()
{
	this->updateMovement();
	this->updatAnimations();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}