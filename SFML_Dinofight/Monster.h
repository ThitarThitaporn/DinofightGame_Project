#pragma once
class Monster
{
private:
	sf::Sprite monsterSprite;
	sf::Texture monsterTex;
	sf::IntRect currentFrame;
	sf::Clock monsterTimer;

	sf::Clock hpClock;

	//hitbox
	sf::RectangleShape hitboxMonster;

	int type;
	int hpMax;
	int damage;
	int points;

	void initMonsterTex();
	void initMonsterSprite();
	void initAnimation();
	void initVariables();
	void initHitbox();
	void updateHitbox();

public:
	Monster();
	Monster(float pos_x, float pos_y);
	virtual ~Monster();

	int hp;
	float MonsterX;
	const sf::FloatRect getBounds() const;
	const sf::Vector2f getPosition() const;
	const sf::Vector2f setPosition(float x, float y) const;

	//hitbox
	const sf::FloatRect getBoundsHitbox() const;

	//functions
	void updateMovement();
	void updateAnimation();
	void setHP(int n);
	void update();
	void render(sf::RenderTarget& target);
};

