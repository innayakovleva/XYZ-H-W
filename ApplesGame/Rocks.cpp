#include "Rocks.h"
#include "Game.h"
using namespace std;
using namespace sf;
namespace ApplesGame
{


	void InitRocks(Rocks& rocks, const Game& game)
	{
		//rocks.Position = GetRandPositionInScreen(SCREEN_WIDHTH, SCREEN_HEIGHT);
		rocks.sprite.setTexture(game.applesTexture);
		SetSpriteSize(rocks.sprite, PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteRelativeOrigin(rocks.sprite, 0.5f, 0.5f);

	}
	Rectangle GetRocksCollider(const Rocks& rock)
	{
		return { { rock.Position.x - ROCKS_SIZE / 2.f, rock.Position.y - ROCKS_SIZE / 2.f },
					{ ROCKS_SIZE, ROCKS_SIZE } };
	}
	void DrawRocks(Rocks& rocks, RenderWindow& window)
	{
		rocks.sprite.setPosition(rocks.Position.x, rocks.Position.y);
		window.draw(rocks.sprite);

	}
}