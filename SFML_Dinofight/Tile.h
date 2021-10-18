#pragma once
class Tile
{
private:
	sf::Sprite sprite;
	const bool damaging; //const bool not change while the game

public:
	Tile(sf::Texture& texture_sheet, sf::IntRect texture_rect, bool damaging = false);

	const sf::FloatRect getGlobalBounds() const;

	void update();
	void render(sf::RenderTarget& target);
};