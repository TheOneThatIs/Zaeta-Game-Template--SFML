#define WIDTH 900
#define HEIGHT 600
#define TITLE "Jonathan Jackson's Template v0.6"

#include "Gamecore.h"
#include "States\TitleScreen.h"


TitleScreen title;

Vector2f mousePos;

//Create the window
RenderWindow window(VideoMode(WIDTH, HEIGHT), TITLE);
FloatRect size(0, 0, WIDTH, HEIGHT);

GameCore::GameCore(){
	window.setView(View(size));
	window.setFramerateLimit (30);//  =)

	isfullscreen = true; 
	init();

	gameLoop();
}

void GameCore::gameLoop() {
	Clock clock;
	float accumulator = 0.0f;

	while (window.isOpen()) {
		Time dt = clock.restart();
		accumulator += dt.asSeconds();
		while (accumulator >= TIME_STEP) {
			handleEvents();
			update();

			accumulator -= TIME_STEP;
		}

		draw();
	}
}

void GameCore::draw () {
	window.clear (Color::Black);
	manager.drawStates (&window);
	window.display ();
}

void GameCore::handleEvents () {
	Event event;
	while (window.pollEvent (event)) {
		switch (event.type) {
		case Event::Closed:
			window.close ();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::F11)
				toggleFullscreen ();
			break;
		case Event::Resized:
			sf::FloatRect visibleArea (0.0, 0.0, float (event.size.width), float (event.size.height));
			width = event.size.width;
			height = event.size.height;
			size = visibleArea;
			window.setView (View (visibleArea));
			break;
		}
		manager.handleStateEvents (event);
		//TitleScreen t
	}
}

void GameCore::init(){
	manager.pushState (&title);
}

void GameCore::update() {
	mousePos = window.mapPixelToCoords (Mouse::getPosition (window));

	title.update();

	manager.updateStates ();

}

void GameCore::toggleFullscreen(){
	isfullscreen = !isfullscreen;

	if (isfullscreen){
		window.create(sf::VideoMode(width, height), TITLE, Style::Fullscreen);
		window.setView(View(size));
	} else window.create(sf::VideoMode(width, height), TITLE, Style::Default);
}