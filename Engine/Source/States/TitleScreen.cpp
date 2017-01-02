#include "States\TitleScreen.h"

TitleScreen::TitleScreen () {
	titleSplash = spriteManager.makeSprite("Resources/Textures/Title Page Splash.png");

	newGame = Button("NEW GAME", 50, IntRect(326, 187, 272, 110), sf::Color::White, spriteManager.makeSprite("Resources/Textures/UI/Button Title.png", IntRect(0, 0, 272, 110)), spriteManager.makeSprite("Resources/Textures/UI/Button Title.png", IntRect(0, 110, 272, 110)));
	options = Button("", 1, IntRect(810, 525, 60, 50), sf::Color::Black, spriteManager.makeSprite("Resources/Textures/UI/Config.png"), spriteManager.makeSprite("Resources/Textures/UI/Config_h.png"));
}


TitleScreen::~TitleScreen() {}


void TitleScreen::init() {

}

void TitleScreen::destroy () {

}

void TitleScreen::handleEvents (sf::Event event) {
	options.handleEvents(event);
	if(newGame.handleEvents(event))
		manager->changeState(new Play());
}

void TitleScreen::update () {

}

void TitleScreen::pause () {

}

void TitleScreen::resume () {

}

void TitleScreen::draw (sf::RenderWindow *window) {
	spriteManager.draw(titleSplash, 0, 0, *window);

	//Buttons
	newGame.draw(window);
	options.draw(window);
}