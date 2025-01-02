#include <iostream>
#include <deque>
#include <raylib.h>
#include <raymath.h>

#include "Game.h"
#include "Constants.h"

using namespace std;

int main() {
	cout << "Hello, world!" << endl;
	InitWindow(2*offset + cellSize*cellCount, 2*offset + cellSize*cellCount, "Snake");
	SetTargetFPS(60);

	Game game = Game();

	while (WindowShouldClose() == false) {
		BeginDrawing();

		if (game.should_update(game.updateInterval)) {
			game.update();
		}	

		game.get_input();
		game.draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}