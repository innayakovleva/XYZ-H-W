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
	void InitApples(Apples& apples);;
	void DrawApples(Apples& apples, RenderWindow& window);
}