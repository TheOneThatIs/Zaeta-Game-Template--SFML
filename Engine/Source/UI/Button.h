#pragma once

#include<SFML\Graphics.hpp>
#include "..\Util\SpriteManager.h"

enum ButtonState  {
    NORMAL,
    HOVER,
    CLICKED
};

class Button{

	sf::Text text;

    ButtonState state = NORMAL;

	SpriteManager spriteManager;
    
    sf::Sprite normalButton;
    sf::Sprite hoverButton;
	float x, y;
	int width, height;
public:
	Button (sf::String text, int fontSize, sf::IntRect srcRect, sf::Color color = sf::Color::Black);
    Button (sf::String text, int fontSize, sf::IntRect srcRect, sf::Color color, sf::Sprite normal, sf::Sprite hover);
	Button();
	~Button();

	void draw (sf::RenderWindow *window);
	bool handleEvents(sf::Event event);
};