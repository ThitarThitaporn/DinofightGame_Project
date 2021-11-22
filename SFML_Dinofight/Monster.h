#pragma once
class Monster
{
private:
	sf::Sprite monsterSprite;
	sf::Texture monsterTex;
	sf::IntRect currentFrame;
	sf::Clock monsterTimer;

	//hitbox
	sf::RectangleShape hitboxEnemies;

	float MonsterX;
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initMonsterTex();
	void initMonsterSprite();
	void initAnimation();
	void initHitbox();
	void updateHitbox();

public:
	Monster();
	Monster(float pos_x, float pos_y);
	virtual ~Monster();

	const sf::FloatRect getBounds() const;
	const sf::Vector2f getPosition() const;
	const sf::Vector2f setPosition(float x, float y) const;

	//hitbox
	const sf::FloatRect getBoundsHitbox() const;

	//functions
	void updateMovement();
	void updateAnimation();
	void update();
	void render(sf::RenderTarget& target);
};

