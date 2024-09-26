#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
 
//namespace sf
//{
	//class Sprite;
//}


namespace ApplesGame
{

	struct Vector2D
	{
		float x = 0;
		float y = 0;
	};
	typedef Vector2D Position2D;

	struct Rectangle
	{
		Position2D position;
		Vector2D size;
	};
	struct Circle
	{
		Position2D position;
		float radius;
	};

	bool DoShapesCollide(const Rectangle& rect1, const Rectangle& rect2);
	bool DoShapesCollide(const Circle& circle1, const Circle& circle2);
	bool DoShapesCollide(const Rectangle& rect, const Circle& circle);

	Position2D GetRandPositionInRectangle(const Rectangle& rect);

	//Position2D GetRandPositionInScreen(float screenWidth, float screenHeigth);
	//bool isRectanglesCollides(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size);
	//bool isCirclesCollides(Position2D circle1Position, float circle11Radius, Position2D circle2Position, float circle12Radius);
	
	void SetSpriteSize(Sprite& sprite, float desiredWidth, float desiredHeight);
	void SetSpriteRelativeOrigin(Sprite& sprite, float originX, float originY);
}
