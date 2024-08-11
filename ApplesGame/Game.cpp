#include "Game.h"
#include <cassert>
#include "Player.cpp"
namespace ApplesGame
{
	void RestartGame(Game& game)
	{
		InitPlayer(game.player,game);
		//init apples
		for (int i = 0;i < NUM_APPLES;++i)
		{
			InitApples(game.apples[i]);
		}
		// init rocks
		for (int i = 0;i < ROCKS_NUM;++i)
		{
			InitRocks(game.rocks[i]);
		}
		game.numEatenApples = 0;
		game.isGameFinished = false;
		game.gameFinishTime = 0;

	}

	void InitGame(Game& game)
	{
		//RESOURCES
		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(game.applesTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(game.rocksTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
		
		// init background
		game.background.setSize(Vector2f(SCREEN_WIDHTH, SCREEN_HEIGHT));
		game.background.setFillColor(Color::Black);
		game.background.setPosition(0.f, 0.f);
		RestartGame(game);
	}

	void GameUpdate(Game& game, float deltaTime)
	{
		// update game state
		// ввод с клавиатуры
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			game.player.playerDirection = PlayerDirection::Right;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			game.player.playerDirection = PlayerDirection::Up;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			game.player.playerDirection = PlayerDirection::Left;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			game.player.playerDirection = PlayerDirection::Down;
		}

		switch (game.player.playerDirection)
		{
		case PlayerDirection::Right:
		{
			game.player.playerPosition.x += game.player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDirection::Up:
		{
			game.player.playerPosition.y -= game.player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDirection::Left:
		{
			game.player.playerPosition.x -= game.player.playerSpeed * deltaTime;
			break;
		}
		case PlayerDirection::Down:
		{
			game.player.playerPosition.y += game.player.playerSpeed * deltaTime;
			break;
		}
		}
	}

	void drawGame(Game& game, RenderWindow& window)
	{
		window.draw(game.background);
		DrawPlayer(game.player,window);
		for (int i = 0;i < NUM_APPLES;++i)
		{
			game.apples[i].Shape.setPosition(game.apples[i].Position.x, game.apples[i].Position.y);
			window.draw(game.apples[i].Shape);
		}
		
		for (int i = 0;i < ROCKS_NUM;++i)
		{
			game.rocks[i].Shape.setPosition(game.rocks[i].Position.x, game.rocks[i].Position.y);
			window.draw(game.rocks[i].Shape);
		}
		window.draw(game.player.sprite);

	}
}