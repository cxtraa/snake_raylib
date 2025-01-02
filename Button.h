#pragma once
#include <raylib.h>

class Button {
public:
	int posX;
	int posY;
	int width;
	int height;
	Rectangle bounds;
	int textSize;
	const char* text;
	int state;

	Button(int posX, int posY, int width, int height, int textSize, const char* text);

	void update();
	void draw();
};