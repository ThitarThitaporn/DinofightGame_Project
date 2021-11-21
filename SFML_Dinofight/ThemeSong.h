#pragma once
class ThemeSong
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
public:
	ThemeSong();
	~ThemeSong();
	void Play();

};

