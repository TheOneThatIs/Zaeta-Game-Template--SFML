#include "Util\SpriteManager.h"
#include<iostream>

std::vector<sf::Texture*> images;

SpriteManager::SpriteManager(){
    font.loadFromFile ("Resources/Fonts/consola.ttf");
	progress = 0;
	time = 0;
}

sf::Sprite SpriteManager::makeSprite (sf::String filepath) {
   images.push_back (new sf::Texture ());
   images[images.size () - 1]->loadFromFile (filepath);
   return sf::Sprite (*(images[images.size () - 1]));
}

sf::Sprite SpriteManager::makeSprite (sf::String filepath, sf::IntRect &area) {
    sf::Texture texture;
    images.push_back (new sf::Texture());
    
    images[images.size () - 1]->loadFromFile (filepath);
    sf::Sprite sprite (*(images[images.size () - 1]));
    sprite.setTextureRect (area);
    return sprite;
}

void SpriteManager::draw(sf::Sprite sprite, float x, float y, sf::RenderWindow &window){
	sprite.setPosition(x, y);
	window.draw(sprite);
}

/**
Text drawing for buttons.
*/
void SpriteManager::draw (sf::Text button_text, int x, int y, int width, int height, sf::RenderWindow &window) {
	

	button_text.setFont (font);
	sf::FloatRect text_rect = button_text.getLocalBounds ();
	button_text.setPosition ((x + (width / 2)) - (button_text.getLocalBounds ().width / 2), (y + (height / 2)) - (button_text.getLocalBounds ().height));//Centers text to button.

	window.draw (button_text);
}

void SpriteManager::drawText (sf::String text, int x, int y, int fontSize, sf::Color color, sf::RenderWindow &window) {
    sf::Text text2;
    text2.setCharacterSize (fontSize);
    text2.setColor (color);
    text2.setString (text);

    text2.setFont (font);
    text2.setPosition ((float)x, (float)y);

    window.draw (text2);
}