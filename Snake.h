#pragma once
#include <deque>
#include <raylib.h>
#include "State.h"
#include "Difficulty.h"

class Snake {
public:
	std::deque<Vector2> body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
	Vector2 direction = { 1, 0 };
	bool addSegment = false;

	void draw();
	void update(Difficulty difficulty);
	void reset();
};