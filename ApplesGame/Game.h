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
	Rectangle screenRect;
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

	Sound ApplesEatSound;
	Sound DeathSound;

	Texture playerTexture;
	Texture applesTexture;
	Texture rocksTexture;
	SoundBuffer eatApplesSoundBuffer;
	SoundBuffer gameOverSoundBuffer;
};


void InitGame(Game& game);
void RestartGame(Game& game);
void GameUpdate(Game& game, float deltaTime);
void drawGame(Game& game,RenderWindow& window);


void DeinitializeGame(Game& game);


void StartPlayingState(Game& game);
void UpdatePlayingState(Game& game, float deltaTime);

void StartGameoverState(Game& game);
void UpdateGameoverState(Game& game, float deltaTime);
}