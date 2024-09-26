// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "Constants.h"
#include "Player.h"

using namespace std;
using namespace sf;



int main()
{
	using namespace ApplesGame;
	unsigned int seed = (unsigned int)time(nullptr);
	srand(seed);
	//int playerDirection = 0;
	
	//init window
	RenderWindow window(VideoMode(SCREEN_WIDHTH, SCREEN_HEIGHT), "Apples game!");
	
	//init game
	Game game;
	InitGame(game);
	
	//game clock
	Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();
	


	//Main Loop

	
	while (window.isOpen())
	{
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		//read event
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

		
			window.clear();
			drawGame(game, window);
			window.display();

			DeinitializeGame(game);
			return 0;
		}
	}
