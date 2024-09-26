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

	void SetPlayerDirection(Player& player, PlayerDirection direction)
	{
		player.playerDirection = direction;
	}

	void SetPlayerPosition(Player& player, const Position2D& position)
	{
		player.playerPosition = position;
	}

	void SetPlayerSpeed(Player& player, float speed)
	{
		player.playerSpeed = speed;
	}

	float GetPlayerSpeed(const Player& player)
	{
		return player.playerSpeed;
	}

	Rectangle GetPlayerCollider(const Player& player)
	{
		return { { player.playerPosition.x - PLAYER_SIZE / 2.f, player.playerPosition.y - PLAYER_SIZE / 2.f },
			{ PLAYER_SIZE, PLAYER_SIZE } };
	}

	void UpdatePlayer(Player& player, float deltaTime)
	{
		switch (player.playerDirection)
		{
		case PlayerDirection::Right:
		{
			player.playerPosition.x += player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDirection::Up:
		{
			player.playerPosition.y -= player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDirection::Left:
		{
			player.playerPosition.x -= player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDirection::Down:
		{
			player.playerPosition.y += player.playerSpeed * deltaTime;
			break;
		}
		}
	}

	void DrawPlayer(Player& player, sf::RenderWindow& window)
	{
		player.sprite.setPosition(player.playerPosition.x, player.playerPosition.y);
		window.draw(player.sprite);

		// Orient player sprite according to player direction
		if (player.playerDirection == PlayerDirection::Left)
		{
			SetSpriteSize(player.sprite, -PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation(0.f);
		}
		else
		{
			SetSpriteSize(player.sprite, PLAYER_SIZE, PLAYER_SIZE);
			player.sprite.setRotation((float)player.playerDirection * -90.f);
		}
	}
}


