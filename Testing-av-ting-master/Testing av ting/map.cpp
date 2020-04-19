#include "map.h"
#include "TextureManager.h"
#include <vector>
#include <iostream>


std::vector<std::vector<int>> PacmanMap =
{
	{1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2},
	{6,34,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{6,0,1,5,5,5,5,5,2,0,10,5,5,5,5,5,5,5,5,5,5,5,5,2,0,6},
	{6,0,6,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,6},
	{6,0,6,0,1,5,9,0,6,0,10,5,5,5,5,5,5,5,5,11,5,9,0,6,0,6},
	{6,0,6,0,6,0,0,0,6,0,0,0,0,0,0,0,0,0,0,6,0,0,0,6,0,6},
	{6,0,6,0,6,0,1,5,4,0,10,5,5,5,5,5,5,9,0,7,34,10,5,12,0,6},
	{6,0,6,0,6,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,6},
	{6,0,6,0,6,0,6,0,8,0,10,5,5,5,5,5,5,5,2,0,10,2,0,6,0,6},
	{6,0,7,0,6,0,7,0,6,0,0,0,0,0,0,0,0,0,6,0,0,6,0,7,0,6},
	{6,0,0,0,6,0,0,0,6,0,10,5,5,5,5,5,2,0,3,9,0,6,0,0,0,6},
	{14,5,5,5,13,5,5,5,4,0,0,0,0,0,0,0,6,0,0,0,0,6,0,8,0,6},
	{6,0,0,0,0,0,0,0,0,0,1,5,5,5,2,0,3,5,5,11,5,4,0,6,0,6},
	{6,0,8,0,8,0,1,5,5,5,12,0,0,0,6,0,0,0,0,6,0,0,0,6,0,6},
	{6,0,6,0,6,0,6,0,34,0,7,0,8,0,3,5,5,9,0,7,0,10,5,12,0,6},
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
	{6,34,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
	{3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4},
	{16,17,18,22,16,29,30,31,32,33,16,19,19,19,19,19,16,16,16,16,16,16,16,16,16,16}
};
std::vector<std::vector<int>> PacmanMap2 =
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
	{16,17,18,22,16,29,30,31,32,33,16,19,19,19,19,19,16,16,16,16,16,16,16,16,16,16}
};

std::vector<std::vector<int>> getMap(bool won) {
	if (won) {
		return PacmanMap2;
	}else{
	return PacmanMap;
	}
}

int Map::scoreTypeConverter(int points) {
	int x;
	switch (points) {
	case 0: 
		return x=19;
		break;
	case 1:
		return x=20;
		break;
	case 2:
		return x=21;
		break;
	case 3:
		return x=22;
		break;
	case 4:
		return x=23;
		break;
	case 5:
		return x=24;
		break;
	case 6:
		return x=25;
		break;
	case 7:
		return x=26;
		break;
	case 8:
		return x=27;
		break;
	case 9:
		return 28;
		break;
	default:
		break;
	
	}
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
	zero = TextureManager::LoadTexture("assets/0.png");
	one = TextureManager::LoadTexture("assets/1.png");
	two = TextureManager::LoadTexture("assets/2.png");
	three = TextureManager::LoadTexture("assets/3.png");
	four = TextureManager::LoadTexture("assets/4.png");
	five = TextureManager::LoadTexture("assets/5.png");
	six = TextureManager::LoadTexture("assets/6.png");
	seven = TextureManager::LoadTexture("assets/7.png");
	eight = TextureManager::LoadTexture("assets/8.png");
	nine = TextureManager::LoadTexture("assets/9.png");
	letterS = TextureManager::LoadTexture("assets/S.png");
	letterC = TextureManager::LoadTexture("assets/C.png");
	letterO = TextureManager::LoadTexture("assets/O.png");
	letterR = TextureManager::LoadTexture("assets/R.png");
	letterE = TextureManager::LoadTexture("assets/E.png");
	bigPellet = TextureManager::LoadTexture("assets/BigPellet.png");


	src.x = 0;
	src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = dest.y = 0;
}

void Map::DrawMap(int mapX,int mapY, bool pelletHit, int deaths, int points, bool won)
{
	int type = 0;
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 26; j++) {
			if (won) {
				type = PacmanMap2[i][j];
			}
			else {
				type = PacmanMap[i][j];
			}
			
			dest.x = j * 32;
			dest.y = i * 32;

			
			if (pelletHit&&i==mapY&&j==mapX&&!won) {
				PacmanMap[mapY][mapX] = 16;
			}
			else if (pelletHit && i == mapY && j == mapX && won) {
				PacmanMap2[mapY][mapX] = 16;
			}
			if (type == 22 && deaths > 0) {
				type -= deaths;
			}


			if (points >= 10000 && i == 30 && j == 11) {
				type = Map::scoreTypeConverter( points / 10000);
				points = points % 10000;
			}
			if (points >= 1000 && i == 30 && j == 12 && points < 10000) {
				type = Map::scoreTypeConverter( points / 1000);
				points = points % 1000;
			}
			if (points >= 100 && i == 30 && j == 13 && points < 1000) {
				type = Map::scoreTypeConverter( points / 100);
				points = points % 100;
			}
			if (points > 0 && i == 30 && j == 14 && points < 100) {
				type = Map::scoreTypeConverter(points / 10);
				
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
				TextureManager::Draw(zero, src, dest);
				break;
			case 20:
				TextureManager::Draw(one, src, dest);
				break;
			case 21:
				TextureManager::Draw(two, src, dest);
				break;
			case 22:
				TextureManager::Draw(three, src, dest);
				break;
			case 23:
				TextureManager::Draw(four, src, dest);
				break;
			case 24:
				TextureManager::Draw(five, src, dest);
				break;
			case 25:
				TextureManager::Draw(six, src, dest);
				break;
			case 26:
				TextureManager::Draw(seven, src, dest);
				break;
			case 27:
				TextureManager::Draw(eight, src, dest);
				break;
			case 28:
				TextureManager::Draw(nine, src, dest);
				break;
			case 29:
				TextureManager::Draw(letterS, src, dest);
				break;
			case 30:
				TextureManager::Draw(letterC, src, dest);
				break;
			case 31:
				TextureManager::Draw(letterO, src, dest);
				break;
			case 32:
				TextureManager::Draw(letterR, src, dest);
				break;
			case 33:
				TextureManager::Draw(letterE, src, dest);
				break;
			case 34:
				TextureManager::Draw(blank, src, dest);
				TextureManager::Draw(bigPellet, src, dest);
				break;
			default:
				break;
			}
		}
	}
}