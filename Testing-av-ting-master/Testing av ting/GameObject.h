#pragma once
#include "Game.h"



class GameObject 
{
public :
	bool animated = false;
	int frames = 0;
	int speed = 100;
	int distance = 0;
	int points = 0;
	int deaths = 0;
	char mButton;
	SDL_Point center = { 8,8 };
	bool reverse= false;
	bool collide = false;
	bool dead;
	bool won;
	float angle;
	int mapX;
	int mapY;
	bool pelletHit = false;

	GameObject(const char* texturesheet, int x, int y, int nFrames, int mSpeed);
	~GameObject();

	void move(char button);
	
	void blinkyMove(int x,int y);
	void pinkyMove(int x, int y);
	void inkyMove(int x, int y);
	void clydeMove(int x, int y);

	int collisonCheck();
	
	int getXPos();
	int getYPos();
	int getMapX();
	int getMapy();
	int getDeaths();
	bool getPelletHit();
	bool getDeath(int bx, int by, int px, int py, int ix, int iy, int cx, int cy);
	bool getWon();

	void Update();
	void Render();
	
	
private:

	int cnt = 0;
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;



};