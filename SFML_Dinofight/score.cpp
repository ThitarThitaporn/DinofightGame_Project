#include "stdafx.h"
#include "score.h"

score::score()
{
	font.loadFromFile("font/dinosaurtext2.ttf");
	sf::Text ttext("ScoreBoard", font, 80);
	main = ttext;
	main.setFillColor(sf::Color::White);
	main.setOrigin(sf::Vector2f(main.getGlobalBounds().width / 2, 0));
	main.setPosition(sf::Vector2f(540, 50));
	for (int i = 0; i < 5; i++)
	{
		scoretext[i].setCharacterSize(40);
		scoretext[i].setFillColor(sf::Color::White);
		scoretext[i].setPosition(540, 200 + (i * 80));
		scoretext[i].setFont(font);
	}
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

void score::Drawscore(sf::RenderWindow& window)
{
	string stream ss[5];
	ReadFile();
	fclose(this->fp);
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
