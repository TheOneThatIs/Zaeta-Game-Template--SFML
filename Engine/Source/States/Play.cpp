#include "States\Play.h"

using namespace std;

Play::Play(){
	
}


Play::~Play(){

}

void Play::init(){
	mapManager.loadMap("C:/Users/TheOneThatIs720/Documents/Visual Studio 2015/Projects/Zaeta Game Template- SFML/Zaeta Game Template- SFML/Resources/Maps/Houses/Your House/Your House_Main Layer.sav");
}

void Play::destroy (){

}

void Play::handleEvents (sf::Event event){

}

void Play::draw(sf::RenderWindow *window){
	mapManager.drawMap();
}
void Play::update(){
	
}

void Play::pause(){

}

void Play::resume(){

}
