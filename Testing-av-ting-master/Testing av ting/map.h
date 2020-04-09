#pragma once
#include "Game.h"

class Map
{
public:
	Map();
	~Map();

	void LoadMap(int arr[31][26]);
	void DrawMap();
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

	int map[31][26];

};
