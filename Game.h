#pragma once
#include <raylib.h>
#include "Food.h"
#include "Snake.h"
#include "State.h"
#include "Difficulty.h"
#include "Button.h"
#include "Constants.h"

class Game {
public:
	Snake snake = Snake();
	Food food = Food(snake.body);

	Button easyButton = Button((screenSize - 200)/2, 475, 200, 50, 30, "Easy");
	Button hardButton = Button((screenSize - 200)/2, 550, 200, 50, 30, "Hard");
	Button retryButton = Button((screenSize - 200) / 2, 475, 200, 50, 30, "Menu");

	Sound eatSound;
	Sound wallSound;

	State gameState = TITLE_SCREEN;
	Difficulty difficulty = HARD;

	double lastUpdateTime = 0;
	double updateInterval = titleScreenUpdateInterval;

	int score = 0;

	Game();
	~Game();

	void draw();
	void update();
	void get_input();
	void check_food_collision();
	void check_out_of_bounds();
	void check_self_collision();
	void game_over();

	bool should_update(double interval);
};