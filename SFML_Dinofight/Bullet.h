#pragma once
class Bullet
{
private:
	sf::Sprite bulletFire;
	sf::Texture bulletTex;

	void initBullet();


public:
		Bullet();
		virtual ~Bullet();
		
		void update();
		void render(sf::RenderTarget& target);


};

