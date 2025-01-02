#pragma once
#include <raylib.h>
#include <deque>
#include "State.h"

class Food {
public:
	Vector2 position;
	Texture2D texture;

	Food(std::deque<Vector2>& snakeBody);

	void draw();
	Vector2 generate_random_xy();
	Vector2 generate_random_pos(std::deque<Vector2>& snakeBody);
};