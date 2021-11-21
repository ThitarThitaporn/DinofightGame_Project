#include "stdafx.h"
#include "ThemeSong.h"

ThemeSong::ThemeSong()
{
	buffer.loadFromFile("Sound/gameRun.wav");
	sound.setBuffer(buffer);
	sound.setVolume(1);
}

ThemeSong::~ThemeSong()
{
}

void ThemeSong::Play()
{
	if (sound.getStatus() != sf::Music::Status::Playing)
	{
		sound.play();
	}
}
