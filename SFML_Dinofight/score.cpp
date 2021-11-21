#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "score.h"

using namespace std;
void score::initScoreBackground()
{
	if (!this->scoreBgTex.loadFromFile("texTure/scorebg.png"))
	{
		std::cout << "ERORR Can't load background" << "\n";
	}
	this->scoreBg.setTexture(this->scoreBgTex);
	this->scoreBg.setScale(0.85f, 0.9f);
}
score::score()
{
	this->initScoreBackground();
	font.loadFromFile("font/dinosaurtext2.ttf");
	sf::Text ttext("ScoreBoard", font, 80);
	main = ttext;
	main.setFillColor(sf::Color::Black);
	main.setOrigin(sf::Vector2f(main.getGlobalBounds().width / 2, 0));
	main.setPosition(sf::Vector2f(850, 110));
	for (int i = 0; i < 5; i++)
	{
		scoretext[i].setCharacterSize(35);
		scoretext[i].setFillColor(sf::Color::Black);
		scoretext[i].setPosition(850, 250 + (i * 80));
		scoretext[i].setFont(font);
	}

	font2.loadFromFile("font/rainyhearts.ttf");
	sf::Text backMenu("Press \"Space Bar\" to exit to mainmenu", font2, 40);
	menuPress = backMenu;
	menuPress.setFillColor(sf::Color::Green);
	menuPress.setOrigin(sf::Vector2f(menuPress.getGlobalBounds().width / 2, 0));
	menuPress.setPosition(sf::Vector2f(850, 700));

}

score::~score()
{

}

void score::ReadFile()
{
	fp = fopen("./score.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &Score[i]);
		this->userScore.push_back(make_pair(Score[i], name[i]));
	}
}

void score::wFile()
{
	ReadFile();

	this->name[5] = Pname;
	this->Score[5] = scoreplayer;
	this->userScore.push_back(make_pair(this->Score[5], this->name[5]));
	sort(userScore.begin(), userScore.end());
	//fclose(this->fp);
	fp = fopen("./score.txt", "w");
	for (int i = 5; i > 0; i--)
	{

		strcpy(temp, userScore[i].second.c_str());
		fprintf(fp, "%s %d\n", temp, userScore[i].first);
	}

	for (int i = 0; i < 6; i++)
	{
		userScore.pop_back();
	}
	fclose(this->fp);
}

void score::setscoretext()
{
}

void score::renderScoreBackground(sf::RenderWindow& window)
{
	window.draw(this->scoreBg);
}

void score::Drawscore(sf::RenderWindow& window)
{
	stringstream ss[5];
	ReadFile();
	fclose(this->fp);

	window.draw(menuPress);
	
	for (int i = 0; i < 5; i++) {
		ss[i] << userScore[i].second << "       " << userScore[i].first;
		scoretext[i].setString(ss[i].str());
		scoretext[i].setOrigin(sf::Vector2f(scoretext[i].getGlobalBounds().width / 2, 0));
		window.draw(scoretext[i]);
	}
	while (!userScore.empty())
	{
		userScore.pop_back();
	}

	window.draw(main);

}
