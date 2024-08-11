#include "Math.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

namespace ApplesGame
{

	Position2D GetRandPositionInScreen(float screenWidth, float screenHeigth)
	{
		Position2D result;
		result.x = rand() / (float)RAND_MAX * screenWidth;
		result.y = rand() / (float)RAND_MAX * screenHeigth;
		return result;
	}

	bool isRectanglesCollides(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size)
	{
		float dx = (float)fabs(rect1Position.x - rect2Position.x);
		float dy = (float)fabs(rect2Position.y - rect2Position.y);
		return (dx <= (rect1Size.x + rect2Size.x) / 2.f &&
			dy <= (rect1Size.y + rect2Size.y) / 2.f);
	}

	bool isCirclesCollides(Position2D circle1Position, float circle11Radius, Position2D circle2Position, float circle12Radius)
	{
		float squareDistance = (circle1Position.x - circle2Position.x) * (circle1Position.x - circle2Position.x) +
			(circle1Position.y - circle2Position.y) * (circle1Position.y - circle2Position.y);
		float squareRadiusSum = (circle11Radius + circle12Radius) * (circle11Radius + circle12Radius);
		return squareDistance <= squareRadiusSum;
	}

	void SetSpriteSize(Sprite& sprite, float desiredWidth, float desiredHeight)
	{		
		FloatRect spriteRect= sprite.getLocalBounds();
		Vector2f scale = { desiredWidth / spriteRect.width,desiredHeight / spriteRect.height };
		sprite.setScale(scale);

	}

	void SetSpriteRelativeOrigin(Sprite& sprite, float originX, float originY)
	{
		FloatRect spriteRect = sprite.getLocalBounds();
		sprite.setOrigin(originX * spriteRect.width, originY * spriteRect.height);
	}
}
