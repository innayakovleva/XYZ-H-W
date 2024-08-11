// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"

using namespace std;
using namespace sf;



int main()
{
	using namespace ApplesGame;
	unsigned int seed = (unsigned int)time(nullptr);
	srand(seed);
	int playerDirection = 0;
	
	Game game;
	InitGame(game);
	
	//game clock
	Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();
	
	//init window
	RenderWindow window(VideoMode(SCREEN_WIDHTH, SCREEN_HEIGHT), "Apples game!");
	Position2D playerPosition = { SCREEN_WIDHTH / 2.f ,SCREEN_HEIGHT / 2.f };
	PlayerDirection playerDirection = PlayerDirection::Right;

	//Main Loop
	while (window.isOpen())
	{


		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				break;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
			{
				window.close();
				break;
			}
		}

		if (!game.isGameFinished)
		{

			// collisions
						//Apples
			for (int i = 0;i < NUM_APPLES;++i)
			{
				if (isCirclesCollides(game.player.playerPosition, PLAYER_SIZE / 2.f, game.apples[i].Position, APPLES_SIZE / 2.f))
				{
					game.apples[i].Position = GetRandPositionInScreen(SCREEN_WIDHTH, SCREEN_HEIGHT);
					++game.numEatenApples;
					game.player.playerSpeed += ACCELERATION;
				}
				//squares
				for (int i = 0;i < ROCKS_NUM;++i)
				{
					if (isRectanglesCollides(game.player.playerPosition, { PLAYER_SIZE,PLAYER_SIZE }, game.rocks[i].Position, { ROCKS_SIZE,ROCKS_SIZE }))
					{

					}
				}

			}

			//borders
			if (playerPosition.x - PLAYER_SIZE / 2.f < 0.f || playerPosition.x + PLAYER_SIZE / 2.f > SCREEN_WIDHTH ||
				playerPosition.x - PLAYER_SIZE / 2.f < 0.f || playerPosition.x + PLAYER_SIZE / 2.f > SCREEN_HEIGHT)
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
			}
			window.clear();
			drawGame(game, window);
			window.display();

			DeinitializeGame(game);
			return 0;
		}
	}
}