#include "Snake.h"
#include "State.h"
#include "Constants.h"
#include "Difficulty.h"

#include <raylib.h>
#include <raymath.h>

void Snake::draw() {
	for (unsigned int i = 0; i < body.size(); i++) {
		float x = body[i].x;
		float y = body[i].y;
		Rectangle segment = Rectangle{offset + x*cellSize, offset + y*cellSize, (float) cellSize, (float) cellSize};
		DrawRectangleRounded(segment, 0.5, 6, snakeColor);
	}
}

void Snake::update(Difficulty difficulty) {
	if (addSegment) {
		addSegment = false;
	}
	else {
		body.pop_back();
	}
	Vector2 new_head = Vector2Add(body[0], direction);
	if (difficulty == EASY) {
		double x = new_head.x;
		double y = new_head.y;
		if (x == -1) {
			new_head = Vector2{ (float)cellCount - 1, (float)y };
		}
		else if (x == cellCount) {
			new_head = Vector2{ 0, (float)y };
		}
		else if (y == -1) {
			new_head = Vector2{ (float)x, (float)cellCount - 1 };
		}
		else if (y == cellCount) {
			new_head = Vector2{ (float)x, 0 };
		}
	}
	body.push_front(new_head);
}

void Snake::reset() {
	body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
	direction = { 1, 0 };
}