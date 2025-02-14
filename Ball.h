#pragma once
extern int player_score;
extern int cpu_score;


extern Color  Yellow;

class Ball
{
public:
	float x, y;
	int speed_x, speed_y;
	int radius;
	int speed_choices[2] = { -1,1 };


public:
	void Draw();
	void Update();
	void ResetBall();

};

