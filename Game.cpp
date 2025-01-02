#include <raylib.h>
#include <raymath.h>
#include <string>
#include "Constants.h"
#include "Game.h"
#include "Difficulty.h"

Game::Game() {
	InitAudioDevice();
	eatSound = LoadSound("sounds/eat.mp3");
	wallSound = LoadSound("sounds/wall.mp3");
}

Game::~Game() {
	UnloadSound(eatSound);
	UnloadSound(wallSound);
	CloseAudioDevice();
}

void Game::draw() {
	if (gameState == GAME_MAIN) {
		DrawRectangleLinesEx(Rectangle{ (float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10 }, 5, borderColor);
		DrawText("Snake", offset - 5, 20, 40, textColor);
		DrawText(TextFormat("Score: %i", score), offset - 5, offset + cellSize * cellCount + 10, 40, textColor);
		snake.draw();
		food.draw();
	}
	else if (gameState == TITLE_SCREEN) {
		const char* title = "Snake";
		int titleWidth = MeasureText(title, titleSize);
		DrawText(title, (screenSize - titleWidth)/2, 300, titleSize, textColor);
		easyButton.draw();
		hardButton.draw();
	}
	else if (gameState == GAME_OVER) {
		const char* title = "GAME OVER";
		int titleWidth = MeasureText(title, gameOverTextSize);
		DrawText(title, (screenSize - titleWidth)/2, 325, gameOverTextSize, textColor);
		retryButton.draw();
	}

	ClearBackground(bgColor);
}

void Game::update() {
	if (gameState == GAME_MAIN) {
		updateInterval = gameMainUpdateInterval;
		snake.update(difficulty);
		check_food_collision();
		if (difficulty == HARD) {
			check_out_of_bounds();
		}
		check_self_collision();
	}
	else if (gameState == TITLE_SCREEN) {
		updateInterval = titleScreenUpdateInterval;
		easyButton.update();
		hardButton.update();
		if (easyButton.state == 2) {
			difficulty = EASY;
			gameState = GAME_MAIN;
		}
		if (hardButton.state == 2) {
			difficulty = HARD;
			gameState = GAME_MAIN;
		}
	}
	else if (gameState == GAME_OVER) {
		updateInterval = titleScreenUpdateInterval;
		retryButton.update();
		if (retryButton.state == 2) {
			gameState = TITLE_SCREEN;
		}
	}
}

void Game::get_input() {
	if (gameState == GAME_MAIN) {
		if (IsKeyPressed(KEY_UP) && snake.direction != Vector2{ 0, 1 }) {
			snake.direction = Vector2{ 0,-1 };
		}
		else if (IsKeyPressed(KEY_DOWN) && snake.direction != Vector2{ 0, -1 }) {
			snake.direction = Vector2{ 0, 1 };
		}
		else if (IsKeyPressed(KEY_RIGHT) && snake.direction != Vector2{ -1, 0 }) {
			snake.direction = Vector2{ 1, 0 };
		}
		else if (IsKeyPressed(KEY_LEFT) && snake.direction != Vector2{ 1, 0 }) {
			snake.direction = Vector2{ -1, 0 };
		}
	}
	else if (gameState == TITLE_SCREEN) {
		if (IsKeyPressed(KEY_ENTER)) gameState = GAME_MAIN;
	}
	else if (gameState == GAME_OVER) {
		if (IsKeyPressed(KEY_ENTER)) gameState = TITLE_SCREEN;
	}
}

void Game::check_food_collision() {
	if (food.position == snake.body[0]) {
		food.position = food.generate_random_pos(snake.body);
		snake.addSegment = true;
		PlaySound(eatSound);
		score++;
	}
}

void Game::check_out_of_bounds() {
	int x = snake.body[0].x;
	int y = snake.body[0].y;
	if (!(0 <= x && x < cellCount && 0 <= y && y < cellCount)) {
		game_over();
	}
}

void Game::check_self_collision() {
	for (unsigned int i = 1; i < snake.body.size(); i++) {
		if (snake.body[i] == snake.body[0]) {
			game_over();
			break;
		}
	}
}

bool Game::should_update(double interval) {
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval) {
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

void Game::game_over() {
	snake.reset();
	food.position = food.generate_random_pos(snake.body);
	PlaySound(wallSound);
	score = 0;
	gameState = GAME_OVER;
}