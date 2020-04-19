#pragma once
#include "Game.h"



class GameObject 
{
public :
	bool animated = false;
	int frames = 0;
	int speed = 100;
	int distance = 0;
	int pellets = 0;
	int points = 0;
	int deaths = 0;
	int ghostSpeed = 4;
	int timer;
	char mButton;
	SDL_Point center = { 8,8 };
	bool reverse= false;
	bool collide = false;
	int deadState;
	bool won;
	int mapX;
	int mapY;
	bool pelletHit = false;
	bool newLevel = false;
	bool wonSecond = false;
	bool poweredUp = false;

	GameObject(const char* texturesheet, int x, int y, int nFrames, int mSpeed);

	void move(char button);
	
	void blinkyMove(int x,int y, bool p);
	void pinkyMove(int x, int y, bool p);
	void inkyMove(int x, int y, bool p);
	void clydeMove(int x, int y, bool p);

	int collisonCheck();
	
	int getXPos();
	int getYPos();
	void setXpos(int x);
	void setYpos(int y);
	int getMapX();
	int getMapy();
	int getDeaths();
	int getPoints();
	bool getPelletHit();
	bool getPoweredUp();
	int getDeath(int bx, int by, int px, int py, int ix, int iy, int cx, int cy,bool pu);
	bool getWon();
	bool getWonSecond();

	void Update();
	void Render();
	
private:

	int cnt = 0;
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;



};