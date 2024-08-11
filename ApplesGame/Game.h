#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Math.h"
#include "Constants.h"
#include "Apples.h"
#include "Rocks.h"

namespace ApplesGame
{


struct Game
{
	Player player;
	Apples apples[NUM_APPLES];
	Rocks rocks[ROCKS_NUM];

	//game data
	bool isGameFinished = false;
	float gameFinishTime = 0;
	RectangleShape background;
	int numEatenApples = 0;
	bool isAppleEeaten = false;
	float timeSinceGameFinished = 0;

	Texture playerTexture;
	Texture applesTexture;
	Texture rocksTexture;
};

void RestartGame(Game& game);;
void InitGame(Game& game);
void GameUpdate(Game& game, float deltaTime);
void drawGame(Game& game, RenderWindow& window);
void DeinitializeGame(Game& game)
{}
}