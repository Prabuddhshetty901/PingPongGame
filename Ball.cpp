#include<raylib.h>


#include "Ball.h"



void Ball::Draw() {

		DrawCircle(x, y, radius, Yellow);
	}

void Ball::Update() {
	x += speed_x;
	y += speed_y;

	if (y + radius >= GetScreenHeight() || y - radius <= 0) {
		speed_y *= -1;
	}
	

	if (x + radius >= GetScreenWidth()) {
		cpu_score++;
		ResetBall();
	}
	
	if(x - radius <= 0) {
		player_score++;
		ResetBall();
	}
}

void Ball::ResetBall() {

	x = GetScreenWidth() / 2;
	y = GetScreenHeight() / 2;


	speed_x++;
	speed_y++;

	speed_x *= speed_choices[GetRandomValue(0, 1)];
	speed_y *= speed_choices[GetRandomValue(0, 1)];
}