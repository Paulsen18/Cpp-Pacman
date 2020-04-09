#include "Game.h"
#include "TextureManager.h"
#include <iostream>
#include <SDL_render.h>
#include "SDL_image.h"
#include "GameObject.h"
#include "map.h"

GameObject* player;
GameObject* blinky;
GameObject* dead;
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
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}
		isRunning = true;
		}
		
	player = new GameObject("assets/PacmanSpriteSheetLoop.png", 448 ,600,6,125);

	blinky = new GameObject("assets/BlinkySpriteSheetRight.png", 224, 200,2,100);

	dead = new GameObject("assets/PacmanSpriteSheetDeath.png", 300, 300, 7, 150);

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
			blinky->ChangeSprite('w');
			break;
		case SDLK_UP:
			player->move('w');
			blinky->ChangeSprite('w');
			break;
		case SDLK_a:
			player->move('a');
			blinky->ChangeSprite('a');
			break;
		case SDLK_LEFT:
			player->move('a');
			blinky->ChangeSprite('a');
			break;
		case SDLK_s:
			player->move('s');
			blinky->ChangeSprite('s');
			break;
		case SDLK_DOWN:
			player->move('s');
			blinky->ChangeSprite('s');
			break;
		case SDLK_d:
			player->move('d');
			blinky->ChangeSprite('d');
			break;
		case SDLK_RIGHT:
			player->move('d');
			blinky->ChangeSprite('d');
			break;
		case SDLK_o:
			player->move('o');
			
			break;
		case SDLK_ESCAPE:
			Game::clean();
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
	blinky->Update();
	dead->Update();
	
	
}
void Game::render() 
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	blinky->Render();
	dead->Render();
	SDL_RenderPresent(renderer);

}

void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}


