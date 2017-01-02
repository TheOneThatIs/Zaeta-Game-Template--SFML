#include "UI\Button.h"
#include<iostream>
#include "Util\Utilities.h"


Button::Button (sf::String text, int fontSize, IntRect srcRect, sf::Color color) {
	x = srcRect.left;
	y = srcRect.top;

	this->text.setCharacterSize (fontSize);
	this->text.setColor (color);
	this->text.setString(text);

	width = srcRect.width;
	height = srcRect.height;

    normalButton = spriteManager.makeSprite ("Resources/Textures/UI/Button 2.png", sf::IntRect (0, 0, 138, 38));
    hoverButton = spriteManager.makeSprite ("Resources/Textures/UI/Button 2.png", sf::IntRect (0, 50, 138, 38));
}

Button::Button (sf::String text, int fontSize, IntRect srcRect, sf::Color color, sf::Sprite normal, sf::Sprite hover) {
	x = srcRect.left;
	y = srcRect.top;

    this->text.setCharacterSize (fontSize);
    this->text.setColor (color);
    this->text.setString (text);

	width = srcRect.width;
	height = srcRect.height;

    normalButton = normal;
    hoverButton = hover;
}


Button::Button () {
	width = 100;
	height = 25;
}

Button::~Button () {}

void Button::draw (sf::RenderWindow *window) {
    if (state == NORMAL)
        spriteManager.draw (normalButton, x, y, *window);
    if (state == HOVER)
        spriteManager.draw (hoverButton, x, y, *window);
	spriteManager.draw (text, x, y, width, height, *window);
}

//    !!! BUG !!!    If handleEvents() is not called, the button will not draw.
bool Button::handleEvents (sf::Event event) {
    if (event.type == sf::Event::MouseMoved) {
        if (mousePos.x >= x && mousePos.x <= x + width) {
            if (mousePos.y >= y && mousePos.y <= y + height) {
                state = HOVER;    //Hovering over button
            } else
                state = NORMAL;
        } else
            state = NORMAL;
    }

	if (event.type == sf::Event::MouseButtonReleased) {
		if (mousePos.x >= x && mousePos.x <= x + width) {
			if (mousePos.y >= y && mousePos.y <= y + height) {
				return true;    //Clicked on button.
			}
			else return false;
		}
		else return false;
	}
	else return false;
}