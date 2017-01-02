#include "Util\Animation.h"
#include<iostream>

Animation::Animation () {}

Animation::Animation (String filePath, IntRect srcRect, int pollFrequency, int numFrames) : currentTime(0), isLooped(false), isAnimationFinished(false) {
	spritesheet = spriteManager.makeSprite (filePath);
	
	this->pollFrequency = pollFrequency;
	interval = srcRect.width;
	this->srcRect = srcRect;
	this->numFrames = numFrames;
}


Animation::~Animation(){

}

void Animation::update () {
	currentTime++;
	if(currentTime == pollFrequency){
		if(srcRect.left != srcRect.width*numFrames && !isAnimationFinished)//If not end of animation and animation is not finished
			srcRect.left += srcRect.width;//Next frame

		if(srcRect.left == srcRect.width*(numFrames-1)){//If reached the end of animation
			if(isLooped)
				srcRect.left = 0;//Restart animation
			else isAnimationFinished = true;
		}
	}
	if(currentTime >= pollFrequency)
		currentTime = 0;//Reset timer
}

void Animation::draw (RenderWindow *window, int x, int y) {
	spritesheet.setTextureRect (srcRect);
	spriteManager.draw (spritesheet, (float)x, (float)y, *window);
}

void Animation::setLoop(bool isLooped){
	this->isLooped = isLooped;
}