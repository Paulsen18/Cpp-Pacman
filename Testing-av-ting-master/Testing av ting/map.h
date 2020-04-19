#pragma once
#include "Game.h"
#include <vector>
std::vector<std::vector<int>> getMap(bool won);
class Map
{
public:
	Map();

	void DrawMap(int mapX, int mapY, bool pelletHit, int deaths, int points, bool won);
	int scoreTypeConverter(int points);

	
private:

	SDL_Rect src, dest;

	SDL_Texture* corner1;
	SDL_Texture* corner2;
	SDL_Texture* corner3;
	SDL_Texture* corner4;
	SDL_Texture* wallHor;
	SDL_Texture* wallVer;
	SDL_Texture* blank;
	SDL_Texture* topEnd;
	SDL_Texture* bottomEnd;
	SDL_Texture* leftEnd;
	SDL_Texture* rightEnd;
	SDL_Texture* rlbCorner;
	SDL_Texture* tlbCorner;
	SDL_Texture* tlrCorner;
	SDL_Texture* trbCorner;
	SDL_Texture* allCorner;
	SDL_Texture* pellet;
	SDL_Texture* pacman;
	SDL_Texture* cross;
	SDL_Texture* zero;
	SDL_Texture* one;
	SDL_Texture* two;
	SDL_Texture* three;
	SDL_Texture* four;
	SDL_Texture* five;
	SDL_Texture* six;
	SDL_Texture* seven;
	SDL_Texture* eight;
	SDL_Texture* nine;
	SDL_Texture* letterS;
	SDL_Texture* letterC;
	SDL_Texture* letterO;
	SDL_Texture* letterR;
	SDL_Texture* letterE;
	SDL_Texture* bigPellet;



};
