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
	
		ypos-=4;
		objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoopUp.png");

		
		break;
	case 'a':
		
			xpos-=4;
			objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoopLeft.png");
		 
		break;
	case 's':
		
			ypos+=4;
			objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoopDown.png");
		
		
		break;
	case 'd':
		
			xpos+=4;
			objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoop.png");
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

void GameObject::blinkyMove() {
	if (!reverse && xpos < 768 && ypos==32) {
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetRight.png");
		xpos+=4;
	}
	else if (!reverse && ypos < 896) {
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetDown.png");
		ypos += 4;
		
	} else if (!reverse && xpos > 32 && ypos==896) {
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetLeft.png");
		xpos -= 4;
		
	}
	else if (xpos == 32 && ypos == 896 && !reverse) {
		reverse = true;
	}
	else if (reverse && ypos==896 && xpos<768) {
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetRight.png");
		xpos += 4;
	}
	else if (reverse && ypos > 32 && xpos==768) {
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetUp.png");
		ypos -= 4;
	}
	else if (reverse && ypos == 32 && xpos>32) {
		objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (reverse && ypos == 32 && xpos == 32) {
		reverse = false;
	}
}
void GameObject::pinkyMove() {
	if (!reverse && xpos > 480 && ypos <= 832) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (!reverse && xpos == 480 &&ypos > 800) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetUp.png");
		ypos -= 4;
	}
	else if (!reverse && xpos > 416 && ypos == 800) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (!reverse && xpos == 416 && ypos < 832) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetDown.png");
		ypos += 4;
	}
	else if (!reverse && xpos > 352 && ypos == 832) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (!reverse && xpos == 352 && ypos > 800) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetUp.png");
		ypos -= 4;
	}
	else if (!reverse && xpos > 288 && ypos == 800) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetLeft.png");
		xpos -= 4; 
	}
	else if (!reverse && xpos == 288 && ypos < 832) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetDown.png");
		ypos += 4;
	}
	else if (!reverse && xpos > 96 && ypos == 832) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (!reverse && xpos == 96 && ypos == 832) {
		reverse = true;
	}
	else if (reverse && xpos == 96 && ypos > 736) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetUp.png");
		ypos -= 4;
	}
	else if (reverse && xpos < 160 && ypos == 736) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetRight.png");
		xpos += 4;
	}
	else if (reverse && xpos == 160 && ypos < 768) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetDown.png");
		ypos += 4;
	}
	else if (reverse && xpos <224 && ypos==768) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetRight.png");
		xpos += 4;
	}
	else if (reverse && xpos == 224 && ypos > 736) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetUp.png");
		ypos -= 4;
	}
	else if (reverse && xpos < 544 && ypos == 736) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetRight.png");
		xpos += 4;
	}
	else if (reverse && xpos == 544 && ypos < 832) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetDown.png");
		ypos += 4;
	}
	else if (reverse && xpos < 704 && ypos == 832) {
		objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetRight.png");
		xpos += 4;
	}
	else if (reverse && xpos == 704 && ypos == 832) {
		reverse = false;
	}
}

void GameObject::inkyMove() {
	if (!reverse && xpos == 32 && ypos < 672) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetDown.png");
		ypos += 4;
	}
	else if (!reverse && xpos < 608 && ypos == 672) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetRight.png");
		xpos += 4;
	}
	else if (!reverse && xpos == 608 && ypos < 704) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetDown.png");
		ypos += 4;
	}
	else if (!reverse && xpos < 704 && ypos == 704) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetRight.png");
		xpos += 4;
	}
	else if (xpos == 704 && ypos > 640) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetUp.png");
		ypos -= 4;
		reverse = true;
	}
	else if (reverse && xpos > 672 && ypos == 640) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (reverse && xpos == 672 && ypos > 576) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetUp.png");
		ypos -= 4;
	}
	else if (reverse && xpos < 704 && ypos == 576) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetRight.png");
		xpos += 4;
	}
	else if (reverse && xpos == 704 && ypos > 480) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetUp.png");
		ypos -= 4;
	}
	else if (reverse && xpos > 576 && ypos == 480) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (reverse && xpos == 576 && ypos > 416) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetUp.png");
		ypos -= 4;
	}
	else if (reverse && xpos > 480 && ypos == 416) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (reverse && xpos == 480 && ypos > 352) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetUp.png");
		ypos -= 4;
	}
	else if (reverse && xpos > 288 && ypos == 352) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (reverse && xpos == 288 && ypos < 384) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetDown.png");
		ypos += 4;
	}
	else if (reverse && xpos > 32 && ypos == 384) {
		objTexture = TextureManager::LoadTexture("assets/InkySpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (reverse && xpos == 32 && ypos == 384) {
		reverse = false;
	}


}

void GameObject::clydeMove() {
	if (xpos < 704 && ypos == 96) {
		reverse = false;
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetRight.png");
		xpos += 4;
	}
	else if ( xpos == 704 && ypos < 160) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetDown.png");
		ypos += 4;
	}
	else if ( xpos > 640 && ypos == 160) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetLeft.png");
		xpos -= 4;
	}
	else if ( xpos == 640 && ypos < 224) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetDown.png");
		ypos += 4;
	}
	else if ( xpos > 608 && ypos == 224) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (xpos == 608 && ypos < 288) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetDown.png");
		ypos += 4;
	}
	// !reverse gjør at den ikke går fra 10 til 7 siden 7 og 11 har nesten lik if statement
	else if (!reverse && xpos < 640 && ypos == 288) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetRight.png");
		xpos += 4;	
	}
	else if (xpos == 640 && ypos < 352) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetDown.png");
		ypos += 4;
	}
	else if ( xpos > 544 && ypos == 352) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (!reverse && xpos == 544 && ypos == 352) {
		reverse = true;
	}
	else if (xpos == 544 && ypos > 288) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetUp.png");
		ypos -= 4;
	}
	else if (xpos > 288 && ypos == 288) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetLeft.png");
		xpos -= 4;
	}
	else if (xpos == 288 && ypos > 96) {
		objTexture = TextureManager::LoadTexture("assets/ClydeSpriteSheetUp.png");
		ypos -= 4;
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