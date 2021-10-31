#pragma once
#include<map>
#include"Bullet.h"
enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING };
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	sf::Texture fireBall;
	sf::Sprite FireBalls;
	sf::Clock animationTimer;
	sf::Clock timeJumping;


	//Animation
	short animState;
	sf::IntRect currentFrame;
	bool animationSwitch;
	
	float attackCooldown;
	float attackCooldownMax;

	//Resources
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//time
	float delayJump;
	bool changeJump = true;

	//Fire ball
	int shotTime = 0;
	

	//physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocitMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

	//core

	void initVariable();
	void initTexture();
	void initSprite();
	void initAnimation();
	void initFireball();
	void initPhysics();


public:
	Player();
	virtual ~Player();
	//Accessors
	const bool& getAnimSwitch();
	const sf::FloatRect getGlobalBouds() const;
	const sf::Vector2f getPosition() const;

	//Modifiers
	void setPosition(const float x, const float y);
	void resetVelocityY();
	void resetVelocityX();

	//Accessor
	const sf::Vector2f& getPos() const;
	const bool canAttack();

	//function
	void resetAnimationTimer();
	void Move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void updatAnimations();
	void updateAttack();
	void update();

	//jumping
	bool jumping = false;
	bool jumpingup = false;
	bool gravityBool = false;
	

	void render(sf::RenderTarget& target);

};
