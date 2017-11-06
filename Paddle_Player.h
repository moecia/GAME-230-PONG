#pragma once
#include "Paddle.h"
using namespace sf;
using namespace std;
class Paddle_Player : public Paddle
{
public:
	Paddle_Player(int playerNum);
	void Update();
private:
	int plyarNum;
	float velocityControl = 5.0f;
};