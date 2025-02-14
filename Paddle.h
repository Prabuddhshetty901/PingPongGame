#pragma once
class Paddle
{
public:
	float x, y;
	float width, height;
	int speed;

public :
	void Draw();
	void Update();

protected:
	void LimitMovement();
};



class CpuPaddle : public Paddle{
	public:
		void Update(int ball_y);

};
