#include<iostream>
#include<raylib.h>

#include "Ball.h"
#include "Paddle.h"

using namespace std;


int player_score = 0;
int cpu_score = 0;

Color  Green = Color{ 38, 185, 154, 255 };
Color  Dark_Green = Color{ 20, 160, 133, 255 };
Color  Light_Green = Color{ 129, 204, 184, 255 };
Color  Yellow = Color{ 243, 213, 91, 255 };

int main() {
	
	cout << "Starting the game" << endl;

	const int screen_width = 1280;
	const int screen_height = 800;

	Ball ball;  // Ball object created
	Paddle player; // Player object created
	CpuPaddle cpu;


	InitWindow(screen_width, screen_height, "Pong Game");
	SetTargetFPS(60);


	ball.radius = 20;
	ball.x = screen_width/2;
	ball.y = screen_height / 2;
	ball.speed_x = 7;
	ball.speed_y = 7;


	player.width = 25;
	player.height = 120;
	player.x = screen_width - player.width - 10;
	player.y = screen_height/2 - player.height / 2;
	player.speed = 6;

	cpu.width = 25;
	cpu.height = 120;
	cpu.x = 10;
	cpu.y = screen_height / 2 - cpu.height / 2;
	cpu.speed = 6;
	


	while (WindowShouldClose() == false) {
		BeginDrawing();

		
		//Updating
		ball.Update();
		player.Update();
		cpu.Update(ball.y);

		//Checking for collisions for player
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ player.x, player.y, player.width, player.height })) {
			ball.speed_x *= -1;
		}

		//Checking for collisions for player
		if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ cpu.x, cpu.y, cpu.width, cpu.height })) {
			ball.speed_x *= -1;
		}

		//Clearing Background
		ClearBackground(Dark_Green);

		//Drawing
		DrawRectangle(screen_width/2, 0,screen_width/2, screen_height, Green);
		DrawCircle(screen_width/2, screen_height/2, 150, Light_Green);

		//Drawing
		DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

		ball.Draw();

		cpu.Draw();

		player.Draw();

		DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE);
		DrawText(TextFormat("%i", player_score), 3*screen_width / 4 - 20, 20, 80, WHITE);

		EndDrawing();
	}




	CloseWindow();
	
	return 0;
}