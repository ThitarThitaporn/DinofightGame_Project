#pragma once
class PlayerGUI
{
private:

	sf::Font font;

	//score Bar
	sf::Text scoreTex;
	std::string scoreString;

	//hp bar
	sf::Text hpBarText;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarInner;
	std::string hpBarString;
	float hpBarMaxwidth;

	void initFont();
	void initHpBar();
	void initScoreBar();
	

public:

	PlayerGUI();
	virtual ~PlayerGUI();

	int hp = 100;
	int score = 0;

	//Function
	void setScore(int n);
	void setHp(int n);

	//Update
	void updateScore();
	void updateHpBar();
	void update();

	//render
	void renderScore(sf::RenderTarget& target);
	void renderHpBar(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);


};

