#pragma once
#include <raylib.h>

// Screen dimensions
const int cellSize = 30;
const int cellCount = 25;
const int offset = 75;
const int screenSize = 2 * offset + cellSize * cellCount;

// Text sizes
const int titleSize = 150;
const int gameOverTextSize = 120;

// Update rates
const double titleScreenUpdateInterval = 0.01;
const double gameMainUpdateInterval = 0.1;

// Colors
const Color bgColor = { 50, 50, 50, 255 };
const Color textColor = { 200, 200, 200, 255 };
const Color borderColor = { 200, 200, 200, 255 };
const Color snakeColor = { 200, 200, 200, 255 };
const Color foodColor = { 150, 150, 150, 255 };
const Color buttonNoHoverColor = { 100, 100, 100, 255 };
const Color buttonHoverColor = { 120, 120, 120, 255 };
const Color buttonPressedColor = { 180, 180, 180, 255 };