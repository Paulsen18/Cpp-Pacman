#include "map.h"
#include "TextureManager.h"

int PacmanMap[31][26]
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
	{6,0,6,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,10,4,0,6},
	{6,0,3,5,5,5,5,5,5,5,13,5,5,5,5,5,5,5,5,5,2,0,0,0,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,9,0,8,0,6},
	{14,5,5,5,5,5,2,0,10,5,5,5,5,5,5,5,5,5,2,0,0,0,0,6,0,6},
	{6,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,6,0,10,2,0,6,0,6},
	{6,0,8,0,8,0,0,0,1,5,5,5,11,5,5,5,2,0,6,0,0,6,0,6,0,6},
	{6,0,6,0,3,5,9,0,7,0,0,0,7,0,0,0,7,0,3,5,5,4,0,6,0,6},
	{6,0,6,0,0,0,0,0,0,0,8,0,0,0,8,0,0,0,0,0,0,0,0,6,0,6},
	{6,0,3,5,5,5,9,0,10,5,13,5,5,5,13,9,0,10,5,5,5,5,5,4,0,6},
	{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4}
};

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

	LoadMap(PacmanMap);
	src.x = 0;
	src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[31][26])
{
	for (int rad = 0; rad < 30; rad++)
	{
		for (int kolonne = 0; kolonne < 26; kolonne++) {
			map[rad][kolonne] = arr[rad][kolonne];
		}
	}
}
void Map::DrawMap()
{
	int type = 0;
	for (int rad = 0; rad < 30; rad++)
	{
		for (int kolonne = 0; kolonne < 26; kolonne++) {
			type = map[rad][kolonne];
			dest.x = kolonne * 32;
			dest.y = rad * 32;

			switch (type)
			{
			case 0:
				TextureManager::Draw(blank, src, dest);
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



			default:
				break;
			}
		}
	}
}