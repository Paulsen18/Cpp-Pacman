#include "map.h"
#include "TextureManager.h"
#include <vector>
#include <iostream>


std::vector<std::vector<int>> PacmanMap =
{
	{1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,1,5,5,5,5,5,2,0,10,5,5,5,5,5,5,5,5,5,5,5,5,2,0,6},
	{6,0,6,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,6},
	{6,0,6,0,1,5,9,0,6,0,10,5,5,5,5,5,5,5,5,11,5,9,0,6,0,6},
	{6,0,6,0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,6,0,0,0,6,0,6},
	{6,0,6,0,6,0,1,5,4,0,10,5,5,5,5,5,5,9,0,7,0,10,5,12,0,6},
	{6,0,6,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,6},
	{6,0,6,0,6,0,6,0,8,0,10,5,5,5,5,5,5,5,2,0,10,2,0,6,0,6},
	{6,0,7,0,6,0,7,0,6,0,0,0,0,0,0,0,0,0,6,0,0,6,0,7,0,6},
	{6,0,0,0,6,0,0,0,6,0,10,5,5,5,5,5,2,0,3,9,0,6,0,0,0,6},
	{14,5,5,5,13,5,5,5,4,0,0,0,0,0,0,0,6,0,0,0,0,6,0,8,0,6},
	{6,0,0,0,0,0,0,0,0,0,1,5,5,5,2,0,3,5,5,11,5,4,0,6,0,6},
	{6,0,8,0,8,0,1,5,5,5,12,0,0,0,6,0,0,0,0,6,0,0,0,6,0,6},
	{6,0,6,0,6,0,6,0,0,0,7,0,8,0,3,5,5,9,0,7,0,10,5,12,0,6},
	{6,0,6,0,6,0,6,0,8,0,0,0,6,0,0,0,0,0,0,0,0,0,0,6,0,6},
	{6,0,6,0,6,0,7,0,3,5,5,5,13,5,5,5,5,5,9,0,1,2,0,6,0,6},
	{6,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,14,4,0,6,0,6},
	{6,0,6,0,3,5,5,5,9,0,8,0,10,5,5,5,5,5,5,5,4,0,0,6,0,6},
	{6,0,6,0,0,0,0,0,0,0,6,0,0,0,16,0,0,0,0,0,0,0,10,4,0,6},
	{6,0,3,5,5,5,5,5,5,5,13,5,5,5,5,5,5,5,5,5,2,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,9,0,8,0,6},
	{14,5,5,5,5,5,2,0,10,5,5,5,5,5,5,5,5,5,2,0,0,0,0,6,0,6},
	{6,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,6,0,10,2,0,6,0,6},
	{6,0,8,0,8,0,0,0,1,5,5,5,11,5,5,5,2,0,6,0,0,6,0,6,0,6},
	{6,0,6,0,3,5,9,0,7,0,0,0,7,0,0,0,7,0,3,5,5,4,0,6,0,6},
	{6,0,6,0,0,0,0,0,0,0,8,0,0,0,8,0,0,0,0,0,0,0,0,6,0,6},
	{6,0,3,5,5,5,9,0,10,5,13,5,5,5,13,9,0,10,5,5,5,5,5,4,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4},
	{16,17,18,19,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16}
};

std::vector<std::vector<int>> getMap() {
	return PacmanMap;
}



Map::Map()
{
	
	corner1 = TextureManager::LoadTexture("assets/BottomRightCorner.png");
	corner2 = TextureManager::LoadTexture("assets/BottomLeftCorner.png");
	corner3 = TextureManager::LoadTexture("assets/TopRightCorner.png");
	corner4 = TextureManager::LoadTexture("assets/TopLeftCorner.png");
	wallHor = TextureManager::LoadTexture("assets/HorizontalWall.png");
	wallVer = TextureManager::LoadTexture("assets/VerticalWall.png");
	blank = TextureManager::LoadTexture("assets/Floor.png");
	topEnd = TextureManager::LoadTexture("assets/TopEnd.png");
	bottomEnd = TextureManager::LoadTexture("assets/BottomEnd.png");
	leftEnd = TextureManager::LoadTexture("assets/LeftEnd.png");
	rightEnd = TextureManager::LoadTexture("assets/RightEnd.png");
	rlbCorner = TextureManager::LoadTexture("assets/RightLeftBottomCorner.png");
	tlbCorner = TextureManager::LoadTexture("assets/TopLeftBottomCorner.png");
	tlrCorner = TextureManager::LoadTexture("assets/TopLeftRightCorner.png");
	trbCorner = TextureManager::LoadTexture("assets/TopRightBottomCorner.png");
	allCorner = TextureManager::LoadTexture("assets/AllCorner.png");
	pellet = TextureManager::LoadTexture("assets/Pellet.png");
	pacman = TextureManager::LoadTexture("assets/Pacman.png");
	cross = TextureManager::LoadTexture("assets/X.png");
	one = TextureManager::LoadTexture("assets/1.png");
	two = TextureManager::LoadTexture("assets/2.png");
	three = TextureManager::LoadTexture("assets/3.png");


	src.x = 0;
	src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}

void Map::DrawMap(int mapX,int mapY, bool pelletHit, int deaths)
{
	int type = 0;
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 26; j++) {
			type = PacmanMap[i][j];
			dest.x = j * 32;
			dest.y = i * 32;
			if (pelletHit&&i==mapY&&j==mapX) {
				PacmanMap[mapY][mapX] = 16;
			}
			if (type == 19 && deaths > 0) {
				type += deaths;
			}
			
			switch (type)
			{
			case 0:
				TextureManager::Draw(blank, src, dest);
				TextureManager::Draw(pellet, src, dest);
				break;
			case 1:
				TextureManager::Draw(corner1, src, dest);
				break;
			case 2:
				TextureManager::Draw(corner2, src, dest);
				break;
			case 3: 
				TextureManager::Draw(corner3, src, dest);
				break;
			case 4:
				TextureManager::Draw(corner4, src, dest);
				break;
			case 5:
				TextureManager::Draw(wallHor, src, dest);
				break;
			case 6:
				TextureManager::Draw(wallVer, src, dest);
				break;
			case 7:
				TextureManager::Draw(topEnd, src, dest);
				break;
			case 8:
				TextureManager::Draw(bottomEnd, src, dest);
				break;
			case 9:
				TextureManager::Draw(leftEnd, src, dest);
				break;
			case 10:
				TextureManager::Draw(rightEnd, src, dest);
				break;
			case 11:
				TextureManager::Draw(rlbCorner, src, dest);
				break;
			case 12:
				TextureManager::Draw(tlbCorner, src, dest);
				break;
			case 13:
				TextureManager::Draw(tlrCorner, src, dest);
				break;
			case 14:
				TextureManager::Draw(trbCorner, src, dest);
				break;
			case 15:
				TextureManager::Draw(allCorner, src, dest);
				break;
			case 16:
				TextureManager::Draw(blank, src, dest);
				break;
			case 17:
				TextureManager::Draw(pacman, src, dest);
				break;
			case 18:
				TextureManager::Draw(cross, src, dest);
				break;
			case 19:
				TextureManager::Draw(three, src, dest);
				break;
			case 20:
				TextureManager::Draw(two, src, dest);
				break;
			case 21:
				TextureManager::Draw(one, src, dest);




			default:
				break;
			}
		}
	}
}