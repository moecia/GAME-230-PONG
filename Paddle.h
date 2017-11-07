#pragma once
#ifndef PADDLE_H
#define PADDLE_H
#include "Entity.h"
using namespace sf;
using namespace std;
class Paddle : public Entity
{
public:
	Vector2f velocityPaddle;
	Paddle(int playerIndex);
	virtual void Update(float ball1Pos, float ball2Pos);
private:
	int playerIndex;
	float velocityPlayer = 2.5f;
	float velocityAI = 0.15f;
	float velocityObstacle = 0.1f;
	bool obstableUp;
	bool obstableDown;
};
#endif // !PADDLE_H
