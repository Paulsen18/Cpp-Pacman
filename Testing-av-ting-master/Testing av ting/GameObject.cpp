#include "GameObject.h"
#include "map.h"
#include "TextureManager.h"
#include <iostream>
#include <SDL_mixer.h>



bool dead;

GameObject::GameObject(const char* texturesheet, int x, int y, int nFrames, int mSpeed) {
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
	frames = nFrames;
	speed = mSpeed;
	animated = true;
}

void GameObject::move(char button) {
	
	collide = false;
	collisonCheck();
	int x = xpos;
	int y = ypos;
	int tx = (xpos+16)/32;
	int ty = (ypos+16)/32;
	
	
	
	if (distance == 32) {
		distance = 0;
	}

	if (button != mButton&&distance>0) {
		xpos = tx * 32;
		ypos = ty * 32;
	}
	mButton = button;
	std::vector<std::vector<int>> map = getMap(won);
	if(!collide){
	switch (button) {
	case  'w':
		
		ypos-=4;
		objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoopUp.png");
		distance += 4;

		
		break;
	case 'a':
		
			xpos-=4;
			objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoopLeft.png");
			distance += 4;
		 
		break;
	case 's':
		
			ypos+=4;
			objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoopDown.png");
			distance += 4;
		
		
		break;
	case 'd':
		
			xpos+=4;
			objTexture = TextureManager::LoadTexture("assets/PacmanSpriteSheetLoop.png");
			distance += 4;

		break;
	default:	

		break;
	}
	}
	else if (collide) {
		switch (button) {
		case 'w':
			ypos++;
			break;
		case 'a':
			xpos++;
			break;
		case 's':
			ypos--;
			break;
		case'd':
			xpos--;
			break;
		default:
			break;
		}
	}
	
	if (collisonCheck()) {
		xpos = x;
		ypos = y;
	}

}


void GameObject::blinkyMove(int x, int y, bool p) {
	
	if (p) {
		objTexture = TextureManager::LoadTexture("assets/ScaredGhostSpriteSheet.png");
		timer = 2000;

	}
	else if (!p) {

		if (!reverse && xpos < 768 && ypos == 32) {
			objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetRight.png");
			xpos += 4;
		}
		else if (!reverse && ypos < 896) {
			objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetDown.png");
			ypos += 4;

		}
		else if (!reverse && xpos > 32 && ypos == 896) {
			objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetLeft.png");
			xpos -= 4;

		}
		else if (xpos == 32 && ypos == 896 && !reverse) {
			reverse = true;
		}
		else if (reverse && ypos == 896 && xpos < 768) {
			objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetRight.png");
			xpos += 4;
		}
		else if (reverse && ypos > 32 && xpos == 768) {
			objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetUp.png");
			ypos -= 4;
		}
		else if (reverse && ypos == 32 && xpos > 32) {
			objTexture = TextureManager::LoadTexture("assets/BlinkySpriteSheetLeft.png");
			xpos -= 4;
		}
		else if (reverse && ypos == 32 && xpos == 32) {
			reverse = false;
		}
	}
}
void GameObject::pinkyMove(int x, int y,bool p) {

	if (p) {
		objTexture = TextureManager::LoadTexture("assets/ScaredGhostSpriteSheet.png");
		timer = 2000;

	}
	else if (!p) {

		if (!reverse && xpos > 480 && ypos <= 832) {
			objTexture = TextureManager::LoadTexture("assets/PinkySpriteSheetLeft.png");
			xpos -= 4;
		}
		else if (!reverse && xpos == 480 && ypos > 800) {
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
		else if (reverse && xpos < 224 && ypos == 768) {
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
}

void GameObject::inkyMove(int x, int y,bool p) {

	if (p) {
		objTexture = TextureManager::LoadTexture("assets/ScaredGhostSpriteSheet.png");
		timer = 2000;

	}
	else if (!p) {

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


}

void GameObject::clydeMove(int x,int y, bool p) {


	if (p) {
		objTexture = TextureManager::LoadTexture("assets/ScaredGhostSpriteSheet.png");
		timer = 2000;

	}else if(!p){
	
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
	// !reverse gj�r at den ikke g�r fra 10 til 7 siden 7 og 11 har nesten lik if statement
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
}

int GameObject::collisonCheck() {

		Mix_Music* chomp = Mix_LoadMUS("assets/Chomp.mp3");

	int x = xpos+31;
	int y = ypos+31;
	int fx = xpos / 32;
	int fy = ypos / 32;
	int i = x / 32;
	int j = y / 32;
	if (poweredUp && timer > 1) {
		timer--;
	}
	else if (poweredUp && timer == 1) {
		timer--;
		poweredUp = false;

	}
	

	
	std::vector<std::vector<int>> map = getMap(won);

	if (16>map[j][i]&&map[j][i]>0) {
		return collide = true;
	}
	else if (16>map[fy][fx]&&map[fy][fx]>0) {
		return collide = true;
	}
	else if (16>map[j][fx]&&map[j][fx]>0) {
		return collide = true;
	}
	else if (16>map[fy][i]&&map[fy][i]>0) {
		return collide = true;
	}
	else if (map[j][i] == 0) {
		mapX = i;
		mapY = j;
		if (!Mix_PlayingMusic()) {
			Mix_PlayMusic(chomp, 0);
		}
		pelletHit = true;
		pellets++;
		points += 50;
		if (pellets == 378) {
			won = true;	
		}
		if (won && pellets == 758) {
				wonSecond = true;
				
		}
		return collide = false;
		
	}
	else if (map[j][i] == 34) {
		mapX = i;
		mapY = j;
		if (!Mix_PlayingMusic()) {
			Mix_PlayMusic(chomp, 0);
		}
		pelletHit = true;
		pellets++;
		points += 250;
		timer = 500;

		if (pellets == 378) {
			won = true;
		}
		if (won && pellets == 758) {
			wonSecond = true;
		}
		poweredUp = true;
		return collide = false;
	}
	else if (map[j][i] == 16) {
		return collide = false;
	}
	
	else {
		return 0;
	}

	
}

int GameObject::getXPos() {
	return xpos;
}
void GameObject::setXpos(int x) {
	xpos = x;
}

int GameObject::getYPos() {
	return ypos;
}

void GameObject::setYpos(int y){
	ypos = y;
}

int GameObject::getMapX() {
	return mapX;
}
int GameObject::getMapy() {
	return mapY;
}
int GameObject::getPoints() {
	return points;
}

bool GameObject::getPelletHit() {
	return pelletHit;
}

bool GameObject::getPoweredUp() {
	return poweredUp;
}


int GameObject::getDeath(int bx,int by, int px, int py, int ix, int iy, int cx, int cy, bool pu) {
	deadState = 0;
	int x = xpos / 32;
	int y = ypos /32;
	int bX = bx / 32;
	int bY = by / 32;
	int pX = px / 32;
	int pY = py / 32;
	int iX = ix / 32;
	int iY = iy / 32; 
	int cX = cx / 32;
	int cY = cy / 32;
	

	std::vector<std::vector<int>> map = getMap(won);
	if (pu && (y == bY && x == bX)) {
		deadState = 1;
		points += 750;
	}
	else if (pu&&(y == pY && x == pX)) {
		deadState = 2;
		points += 750;

	}
	else if (pu && (y == iY && x == iX)) {
		deadState = 3;
		points += 750;
	}else if(pu&&(y == cY && x == cX)) {
		deadState = 4;
		points += 750;
	}else if (!pu&&(y == bY && x == bX)||
		(y == pY && x == pX)||
		(y == iY && x == iX)||
		(y == cY && x == cX)) {
		Mix_Music* death = Mix_LoadMUS("assets/Death.mp3");
		Mix_PlayMusic(death, 0);
		deadState = 5;
		deaths++;
		xpos = 448;
		ypos = 608;
	}
	

	return deadState;
}

int GameObject::getDeaths() {
	return deaths;
}

bool GameObject::getWon() {
	return won;
}
bool GameObject::getWonSecond() {
	return wonSecond;
}




void GameObject::Update() 
{	

	srcRect.h = 31;
	srcRect.w = 31;
	srcRect.x = 0;
	srcRect.y = 0;

	if (animated) {
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;	
	if (won&&!newLevel) {
		xpos = 448;
		ypos = 608;
		newLevel = true;
	}
}

void GameObject::Render() 
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
