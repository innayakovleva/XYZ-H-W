#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"
#include "Constants.h"

using namespace std;
using namespace sf;

namespace ApplesGame
{
	struct Game;

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
	
		
	
	void InitPlayer(Player& player,const Game& game);;
	void SetPlayerDirection(Player& player, PlayerDirection direction);
	void SetPlayerPosition(Player& player, const Position2D& position);
	void SetPlayerSpeed(Player& player, float speed);
	float GetPlayerSpeed(const Player& player);
	Rectangle GetPlayerCollider(const Player& player);
	void UpdatePlayer(Player& player, float deltaTime);
	void DrawPlayer(Player& plater, sf::RenderWindow& window);
}