#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include"stdafx.h"
#include"score.h"

class score
{

private:
	sf::Font font;
	sf::Font font2;
	sf::Text main, scoretext[5],menuPress;
	sf::Sprite scoreBorder;
	FILE* fp;
	sf::Text top[5];
	int i;
	char temp[255];
	size_t Score[6];
	std::string name[6];
	std::vector<std::pair<int, std::string>> userScore;
	
	size_t getscore;
	std::string getName;

	sf::Sprite scoreBg;
	sf::Texture scoreBgTex;

	void initScoreBackground();


public:

	score();
	~score();
	void ReadFile();
	void wFile();
	std::string Pname;
	int scoreplayer;
	void setscoretext();

	void renderScoreBackground(sf::RenderWindow& window);
	void Drawscore(sf::RenderWindow& window);

};

