#include "Game.h"
#include <cassert>
#include "Player.cpp"
namespace ApplesGame
{
	 /**void RestartGame(Game& game)
	{
		InitPlayer(game.player,game);
		//init apples
		for (int i = 0;i < NUM_APPLES;++i)
		{
			InitApples(game.apples[i],game);
		}
		// init rocks
		for (int i = 0;i < ROCKS_NUM;++i)
		{
			InitRocks(game.rocks[i],game);
		}
		

	}/**/

	void InitGame(Game& game)
	{
		//RESOURCES
		assert(game.playerTexture.loadFromFile(RESOURCES_PATH + "\\Player.png"));
		assert(game.applesTexture.loadFromFile(RESOURCES_PATH + "\\Apple.png"));
		assert(game.rocksTexture.loadFromFile(RESOURCES_PATH + "\\Rock.png"));
		assert(game.eatApplesSoundBuffer.loadFromFile(RESOURCES_PATH + "\\AppleEat.wav"));
		assert(game.gameOverSoundBuffer.loadFromFile(RESOURCES_PATH + "\\Death.wav"));

		// Init game objects
		game.screenRect = { 0.f, 0.f, SCREEN_WIDHTH, SCREEN_HEIGHT };
		InitPlayer(game.player, game);
		game.numEatenApples = 0;
		game.isGameFinished = false;

		// Init apples
		for (int i = 0; i < NUM_APPLES; ++i)
		{
			InitApples(game.apples[i], game);
		}

		// Init rocks
		for (int i = 0; i < ROCKS_NUM; ++i)
		{
			InitRocks(game.rocks[i], game);
		}

		// Init background
		game.background.setSize(sf::Vector2f(game.screenRect.size.x, game.screenRect.size.y));
		game.background.setFillColor(sf::Color::Black);
		game.background.setPosition(0.f, 0.f);


		// Init sounds
		game.ApplesEatSound.setBuffer(game.eatApplesSoundBuffer);
		game.DeathSound.setBuffer(game.gameOverSoundBuffer);
	
		StartPlayingState(game);
		//RestartGame(game);
	}

	/**void GameUpdate(Game& game, float deltaTime)
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

		// collisions
		//Apples
		for (int i = 0; i < NUM_APPLES; ++i)
		{
			if (isCirclesCollides(game.player.playerPosition, PLAYER_SIZE / 2.f, game.apples[i].Position, APPLES_SIZE / 2.f))
			{
				game.apples[i].Position = GetRandPositionInScreen(SCREEN_WIDHTH, SCREEN_HEIGHT);
				++game.numEatenApples;
				game.player.playerSpeed += ACCELERATION;
				game.ApplesEatSound.play();
			}
		}

		//rocs
		for (int i = 0; i < ROCKS_NUM; ++i)
		{
			if (isRectanglesCollides(game.player.playerPosition, { PLAYER_SIZE,PLAYER_SIZE },
				game.rocks[i].Position, { ROCKS_SIZE,ROCKS_SIZE }))
			{
				game.isGameFinished = true;
				game.timeSinceGameFinished = 0.f;
				game.DeathSound.play();
			}
		}
		//borders
		if (game.player.playerPosition.x - PLAYER_SIZE / 2.f < 0.f || game.player.playerPosition.x + PLAYER_SIZE / 2.f > SCREEN_WIDHTH ||
			game.player.playerPosition.x - PLAYER_SIZE / 2.f < 0.f || game.player.playerPosition.x + PLAYER_SIZE / 2.f > SCREEN_HEIGHT)
		{
			game.isGameFinished = true;
			game.timeSinceGameFinished = 0.f;
		}
		else
		{
			if (currentTime - game.gameFinishTime <= PAUSE_LENGTH)
			{
				game.background.setFillColor(Color::Red);
			}
			//reset background
			else
			{
				game.background.setFillColor(Color::Black);
				RestartGame(game);
			}

		}/**/


		void StartPlayingState(Game& game)
		{
			SetPlayerPosition(game.player, { SCREEN_WIDHTH / 2.f, SCREEN_HEIGHT / 2.f });
			SetPlayerSpeed(game.player, INITIAL_SPEED);
			SetPlayerDirection(game.player, PlayerDirection::Right);
		}

		void UpdatePlayingState(Game& game, float deltaTime)
		{
			// Handle input
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				SetPlayerDirection(game.player, PlayerDirection::Right);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				SetPlayerDirection(game.player, PlayerDirection::Up);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				SetPlayerDirection(game.player, PlayerDirection::Left);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				SetPlayerDirection(game.player, PlayerDirection::Down);
			}

			UpdatePlayer(game.player, deltaTime);

			// Find player collisions with apples
			for (int i = 0; i < NUM_APPLES; ++i)
			{
				if (DoShapesCollide(GetPlayerCollider(game.player), GetAppleCollider(game.apples[i])))
				{
					SetApplesPosition(game.apples[i], GetRandPositionInRectangle(game.screenRect));
					++game.numEatenApples;
					SetPlayerSpeed(game.player, GetPlayerSpeed(game.player) + ACCELERATION);
					game.ApplesEatSound.play();
					
			}

			// Find player collisions with rocks
			for (int i = 0; i < ROCKS_NUM; ++i)
			{
				if (DoShapesCollide(GetPlayerCollider(game.player), GetRocksCollider(game.rocks[i])))
				{
					StartGameoverState(game);
				}
			}

			// Check screen borders collision
			if (!DoShapesCollide(GetPlayerCollider(game.player), game.screenRect))
			{
				StartGameoverState(game);
			}
		}

		}

		void StartGameoverState(Game& game)
		
		
		{
			game.isGameFinished = true;
			game.gameFinishTime = 0.f;
			game.DeathSound.play();
			
		}

		void UpdateGameoverState(Game& game, float deltaTime)
		{
			if (game.gameFinishTime <= PAUSE_LENGTH)
			{
				game.gameFinishTime += deltaTime;
				game.background.setFillColor(sf::Color::Red);
			}
			else
			{
				// Reset backgound
				game.background.setFillColor(sf::Color::Black);

				StartPlayingState(game);
			}
		}
		

		void drawGame(Game& game, RenderWindow& window)
		{
			window.draw(game.background);
			DrawPlayer(game.player, window);

			for (int i = 0; i < NUM_APPLES; ++i)
			{
				DrawApples(game.apples[i], window);
			}

			for (int i = 0; i < ROCKS_NUM; ++i)
			{
				DrawRocks(game.rocks[i], window);
			}
			window.draw(game.player.sprite);
		}

		void DeinitializeGame(Game& game)
		{
		}
			
		
	
	}