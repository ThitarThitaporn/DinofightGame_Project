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

	//Level
	sf::Text levelTex;
	sf::String levelString;

	void initFont();
	void initHpBar();
	void initScoreBar();
	void initLevelBar();

public:

	PlayerGUI();
	virtual ~PlayerGUI();

	int hp = 100;
	int score = 0;
	int level = 0;

	//Function
	void setScore(int n);
	void setHp(int n);
	void setLevel(int n);

	//Update
	void updateScore();
	void updateHpBar();
	void updatLevel();
	void update();

	//render
	void renderScore(sf::RenderTarget& target);
	void renderHpBar(sf::RenderTarget& target);
	void renderLevel(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);


};

