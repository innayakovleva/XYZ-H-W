#include "Player.h"
#include "Game.h"
//#include "Math.cpp"
using namespace std;
using namespace sf;
namespace ApplesGame
{

	void InitPlayer(Player& player, const Game& game)
	{
		player.playerPosition = { SCREEN_WIDHTH / 2.f ,SCREEN_HEIGHT / 2.f };
		player.playerSpeed = INITIAL_SPEED;
		player.playerDirection = PlayerDirection::Right;
		player.sprite.setTexture(game.playerTexture);
		SetSpriteSize(player.sprite,PLAYER_SIZE, PLAYER_SIZE);
		SetSpriteRelativeOrigin(player.sprite, 0.5f, 0.5f);
	}
	void DrawPlayer(Player& player, RenderWindow& window)
	{
		player.sprite.setPosition(player.playerPosition.x,player.playerPosition.y);
		window.draw(player.sprite);
	}
	
}