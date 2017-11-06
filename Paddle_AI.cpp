#include "Paddle_AI.h"

Paddle_AI::Paddle_AI(int playerNum)
{
	this->setScale(1.0f, .7f);
	this->plyarNum = playerNum;
	this->ball = ball;
	this->speed = 0.1f;
	switch (this->plyarNum)
	{
	case 0:
		this->Load("Paddle_0.png");
		break;
	default:
		this->Load("Paddle_1.png");
		break;
	}
}

void Paddle_AI::SetBallPos( Ball* ball)
{
	this->ball = ball;
}

void Paddle_AI::Update()
{
	if (this->ball != NULL)
	{
		if (this->getPosition().y + this->getGlobalBounds().height / 2 < this->ball->getPosition().y)
		{
			this->move(0, this->speed);
		}

		if (this->getPosition().y + this->getGlobalBounds().height / 2 > this->ball->getPosition().y)
		{
			this->move(0, -this->speed);
		}
	}
	
	Entity::Update();

	if (this->getPosition().y < 0)
		this->move(0, 1.0f);
	if (this->getPosition().y + this->getGlobalBounds().height > 720)
		this->move(0, -1.0f);
}