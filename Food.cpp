#include <deque>
#include <raylib.h>
#include <raymath.h>
#include "Constants.h"
#include "Food.h"

Food::Food(std::deque<Vector2>& snakeBody) {
	position = generate_random_pos(snakeBody);
}

void Food::draw() {
	DrawCircle(cellSize / 2 + offset + position.x * cellSize, cellSize / 2 + offset + position.y * cellSize, cellSize / 2, foodColor);
}

Vector2 Food::generate_random_xy() {
	return Vector2{ (float)GetRandomValue(0, cellCount - 1), (float)GetRandomValue(0, cellCount - 1) };
}

Vector2 Food::generate_random_pos(std::deque<Vector2>& snakeBody) {
	Vector2 position = generate_random_xy();
	if (find(snakeBody.begin(), snakeBody.end(), position) != snakeBody.end()) {
		return generate_random_pos(snakeBody);
	}
	return position;
}