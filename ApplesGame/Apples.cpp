#include "Apples.h"
#include "Game.h"

using namespace sf;
namespace ApplesGame
{

	void InitApples(Apples& apples,const Game& game)
	{
		//apples.Position = GetRandPositionInScreen(SCREEN_WIDHTH, SCREEN_HEIGHT);
		apples.sprite.setTexture(game.applesTexture);
		SetSpriteSize(apples.sprite, APPLES_SIZE, APPLES_SIZE);
		SetSpriteRelativeOrigin(apples.sprite, 0.5f, 0.5f);

	}
	void DrawApples(Apples& apples, RenderWindow& window)
	{
		apples.sprite.setPosition(apples.Position.x, apples.Position.y);
		window.draw(apples.sprite);
		
	}
    void SetApplesPosition(Apples& apples,const Position2D& position)
	{
		apples.Position = position;
	}

	Circle GetAppleCollider(const Apples& apple)
	{
		return { apple.Position, APPLES_SIZE / 2.f };
	}

}