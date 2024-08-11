#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"
using namespace std;
using namespace sf;

namespace ApplesGame
{

	enum class PlayerDirection
	{
		Right = 0,
		Up,
		Left,
		Down
	};
	struct Player
	{
		//playerData
		Position2D playerPosition;
		float playerSpeed = INITIAL_SPEED;
		PlayerDirection playerDirection = PlayerDirection::Right;
		//RectangleShape playerShape;
		Sprite sprite;
	};
	struct Game;
	
	void InitPlayer(Player& player,const Game& game);;
}