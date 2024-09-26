#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"
using namespace std;
using namespace sf;

namespace ApplesGame
{

	struct Rocks
	{
		//rocks data
		//RectangleShape Shape;
		Position2D Position;
		Sprite sprite;
	};
	void InitRocks(Rocks& rocks,const Game& game);
	Rectangle GetRocksCollider(const Rocks& rock);
	void DrawRocks(Rocks& rocks, RenderWindow& window);
}