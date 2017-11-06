#pragma once
#include "Paddle.h"
#include "Ball.h"
using namespace sf;
using namespace std;
class Paddle_AI : public Paddle
{
public:
	Paddle_AI(int playerNum);
	void SetBallPos(Ball* ball);
	void Update();
private:
	Ball* ball;
	int plyarNum;
	float velocityControl = 5.0f;
	float speed;
};