#pragma once

#include"SFML\Graphics.hpp"
#include <vector>

class SpriteManager{
	sf::Font font;
	int progress, time;
public:
	SpriteManager();

	sf::Sprite makeSprite(sf::String filepath);
    sf::Sprite SpriteManager::makeSprite (sf::String filepath, sf::IntRect &area);

	void draw(sf::Sprite sprite, float x, float y, sf::RenderWindow &window);//Regular draw function
	void draw (sf::Text button_text, int x, int y, int width, int height, sf::RenderWindow &window);//Button specific drawing
    void  SpriteManager::drawText (sf::String text, int x, int y, int fontSize, sf::Color color, sf::RenderWindow &window);//Text drawing
};