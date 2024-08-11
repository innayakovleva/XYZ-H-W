#include "Rocks.h"
namespace ApplesGame
{


	void ApplesGame::InitRocks(Rocks& rocks)
	{
		rocks.Position = GetRandPositionInScreen(SCREEN_WIDHTH, SCREEN_HEIGHT);
		rocks.Shape.setSize(Vector2f(ROCKS_SIZE, ROCKS_SIZE));
		rocks.Shape.setFillColor(Color::Yellow);
		rocks.Shape.setOrigin(APPLES_SIZE / 2.f, APPLES_SIZE / 2.f);
		rocks.Shape.setPosition(rocks.Position.x, rocks.Position.y);

	}
	void DrawRocks(Rocks& rocks, RenderWindow& window)
	{
	}
}