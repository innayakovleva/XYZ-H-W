#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"


using namespace std;
using namespace sf;
namespace ApplesGame
{

	struct Apples
	{
		//apples data
		Position2D Position;
		//CircleShape Shape;
		Sprite sprite;
	};

	void InitApples(Apples& apples,const Game& game);
	void DrawApples(Apples& apples,RenderWindow& GetRandPositionInRectanglewindow);
	void SetApplesPosition(Apples& apples,const Position2D& position);
	Circle GetAppleCollider(const Apples& apple);
}