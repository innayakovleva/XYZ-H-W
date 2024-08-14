#include "Rocks.h"
#include "Game.h"
using namespace std;
using namespace sf;
namespace ApplesGame
{


	void InitRocks(Rocks& rocks, const Game& game)
	{
		rocks.Position = GetRandPositionInScreen(SCREEN_WIDHTH, SCREEN_HEIGHT);
		rocks.sprite.setTexture(game.applesTexture);

	}
	void DrawRocks(Rocks& rocks, RenderWindow& window)
	{
		rocks.sprite.setPosition(rocks.Position.x, rocks.Position.y);
		window.draw(rocks.sprite);

	}
}