#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>


GameObject::GameObject(const char* texturesheet, int x, int y)
{

	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

GameObject::GameObject(const char* texturesheet, int x, int y, int nFrames, int mSpeed) {
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	frames = nFrames;
	speed = mSpeed;
	animated = true;
}

GameObject::GameObject(const char* texturesheet, int x, int y, int nFrames, int mSpeed,float mAngle) {
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	frames = nFrames;
	speed = mSpeed;
	animated = true;
	angle = mAngle;
}

void GameObject::ChangeAngle(float nAngle) {
	angle += nAngle;
}

void GameObject::move(char button) {
	switch (button) {
	case  'w':
		for (int i = 0; i < 4;) {
		ypos -= 8;
		objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoopUp.png");
		i++;
		}
		break;
	case 'a':
		for (int i = 0; i < 4;) {
			xpos -= 8;
			objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoopLeft.png");
			i++;
		}	 
		break;
	case 's':
		for (int i = 0; i < 4;) {
			ypos += 8;
			objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoopDown.png");
			i++;
		}
		break;
	case 'd':
		for (int i = 0; i < 4;) {
			xpos += 8;
			objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoop.png");
			i++;
		}
		break;
	case 'o':
		objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetDeath.png");
		break;
	default:
		break;
	}
	if (ypos > 896) {
		ypos = 896;
	}
	else if (ypos < 32) {
		ypos = 32;
	}
	if (xpos > 768) {
		xpos = 768;
	}
	else if (xpos < 32) {
		xpos = 32;
	}
}

void GameObject::ChangeSprite(char button) {
	switch (button) {
	case 'w':
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetUp.png");
		break;
	case 'a':
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetLeft.png");
		break;
	case 's':
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetDown.png");
		break;
	case 'd':
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetRight.png");
		break;
	default:
		break;
	}
}

int GameObject::getXPos() {
	return xpos;
}
int GameObject::getYPos() {
	return ypos;
}


void GameObject::Update() 
{
	//xpos++;
	//ypos++;
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	if (animated) {
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;	
}

void GameObject::Render() 
{
	SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, angle, &center, SDL_FLIP_NONE);
}