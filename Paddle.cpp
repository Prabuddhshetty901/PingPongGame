#include<raylib.h>

#include "Paddle.h"


void Paddle::Draw() {
	DrawRectangleRounded(Rectangle{ x, y, width, height }, 0.8, 0, WHITE);
}

void Paddle :: Update() {
	
	if (IsKeyDown(KEY_UP)) {
		y = y - speed;
	}

	if (IsKeyDown(KEY_DOWN)) {
		y = y + speed;
	}
	
	LimitMovement();
}

void Paddle::LimitMovement() {
	
	if (y <= 0) {
		y = 0;
	}

	if (y + height >= GetScreenHeight()) {
		y = GetScreenHeight() - height;
	}
}