#pragma once
#include "Game.h"

class GameObject 
{
public :
	bool animated = false;
	int frames = 0;
	int speed = 100;
	SDL_Point center = { 8,8 };
	float angle;

	GameObject(const char* texturesheet, int x, int y);
	GameObject(const char* texturesheet, int x, int y, int nFrames, int mSpeed);
	GameObject(const char* texturesheet, int x, int y, int nFrames, int mSpeed,float mAngle);
	~GameObject();

	void ChangeAngle(float nAngle);
	void move(char button);
	void ChangeSprite(char button);
	int getXPos();
	int getYPos();

	void Update();
	void Render();
	
	
private:

	int cnt = 0;
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;



};