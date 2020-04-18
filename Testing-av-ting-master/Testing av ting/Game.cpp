#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include <SDL_render.h>
#include "SDL_image.h"
#include "GameObject.h"
#include "map.h"

GameObject* player;
GameObject* blinky;
GameObject* pinky;
GameObject* inky;
GameObject* clyde;
Map* map;


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::~Game() {

}
Game::Game() {

}
void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Initialised" << std::endl;

		window = SDL_CreateWindow("Pacman", x, y, width, height, flags);
		if (window) {
			std::cout << "Window opened" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer Created" << std::endl;
		}
		isRunning = true;
		}
		
	player = new GameObject("assets/PacmanSpriteSheetLoop.png", 448 ,608,6,125);

	blinky = new GameObject("assets/BlinkySpriteSheetRight.png", 32, 32,2,100);

	pinky = new GameObject("assets/PinkySpriteSheetRight.png", 704, 832, 2, 100);

	inky = new GameObject("assets/InkySpriteSheetRight.png", 32, 384, 2, 100);

	clyde = new GameObject("assets/ClydeSpriteSheetRight.png", 288, 96, 2, 100);

	map = new Map();

	}
void Game::eventHandler()
{
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_w:
			player->move('w');
			break;
		case SDLK_UP:
			player->move('w');
			break;
		case SDLK_a:
			player->move('a');
			break;
		case SDLK_LEFT:
			player->move('a');
			break;
		case SDLK_s:
			player->move('s');
			break;
		case SDLK_DOWN:
			player->move('s');
			break;
		case SDLK_d:
			player->move('d');
			break;
		case SDLK_RIGHT:
			player->move('d');
			break;
		case SDLK_o:
			player->move('o');
			
			break;
		default:
			break;
		}
		
	default:
		break;
	}
}



void Game::update()
{
	
	
	player->Update();
	blinky->blinkyMove(player->getXPos(),player->getYPos());
	blinky->Update();
	pinky->pinkyMove(player->getXPos(), player->getYPos());
	pinky->Update();
	inky->inkyMove(player->getXPos(), player->getYPos());
	inky->Update();
	clyde->clydeMove(player->getXPos(), player->getYPos());
	clyde->Update();
	
	if (player->getDeath(blinky->getXPos(), blinky->getYPos(), pinky->getXPos(), pinky->getYPos(), inky->getXPos(), inky->getYPos(), clyde->getXPos(), clyde->getYPos())) {
		if (player->getDeaths()==3) {
			std::cout << "You Died!" << std::endl;
			Game::clean();
		}

	}
	if (player->getWon()&&player->getWonSecond()) {
		Game::clean();
		std::cout << "You Won!" << std::endl;
		
	}
}
void Game::render() 
{

	SDL_RenderClear(renderer);
	map->DrawMap(player->getMapX(),player->getMapy(),player->getPelletHit(),player->getDeaths(),player->getPoints(),player->getWon());
	player->Render();
	blinky->Render();
	pinky->Render();
	inky->Render();
	clyde->Render();
	SDL_RenderPresent(renderer);

}

void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}


