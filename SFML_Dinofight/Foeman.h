#pragma once
class Foeman
{

	private:
		sf::Sprite foemanSprite;
		sf::Texture foemanTex;
		sf::IntRect currentFrame;
		sf::Clock foemanTimer;
		sf::Clock delayFoeman;

		//hitbox
		sf::RectangleShape hitboxfoeman;

		float FoemanX;
		int type;
		int hp;
		int hpMax;
		int damage;
		int points;

		void initfoemanTex();
		void initfoemanSprite();
		void initAnimation();
		void initHitbox();
		void updateHitbox();

	public:
		Foeman();
		Foeman(float pos_x, float pos_y);
		virtual ~Foeman();

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




