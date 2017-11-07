#include "Paddle.h"
#include "MainGame.h"
#define isAI 0
#define isPlayer 1
Paddle::Paddle(int playerIndex)
{
	this->setScale(1.0f, .7f);
	this->playerIndex = playerIndex;
	switch (this->playerIndex)
	{
	case 0:
		this->Load("Paddle_0.png");
		break;
	case 1:
		this->Load("Paddle_1.png");
		break;
	case 2:
		this->setScale(0.2f, 0.7f);
		this->Load("Paddle_2.png");
		break;

	}
}

void Paddle::Update(float ball1Pos, float ball2Pos)
{
	switch (this->playerIndex)
	{
	case 0:
		this->velocityPaddle.y = (Keyboard::isKeyPressed(Keyboard::Key::S) - Keyboard::isKeyPressed(Keyboard::Key::W)) / velocityPlayer;
		break;
	case 1:
		if(gameMode == isPlayer)
			this->velocityPaddle.y = (Keyboard::isKeyPressed(Keyboard::Key::Down) - Keyboard::isKeyPressed(Keyboard::Key::Up)) / velocityPlayer;
		if (gameMode == isAI)
		{
			if (ball1Pos > ball2Pos)
			{
				if (this->getPosition().y + this->getGlobalBounds().height / 2 < ball1Pos)
				{
					this->move(0, this->velocityAI);
				}

				if (this->getPosition().y + this->getGlobalBounds().height / 2 > ball1Pos)
				{
					this->move(0, -this->velocityAI);
				}
			}
			if (ball1Pos <= ball2Pos)
			{
				if (this->getPosition().y + this->getGlobalBounds().height / 2 < ball2Pos)
				{
					this->move(0, this->velocityAI);
				}

				if (this->getPosition().y + this->getGlobalBounds().height / 2 > ball2Pos)
				{
					this->move(0, -this->velocityAI);
				}
			}

		}
		break;
	case 2:
		if (this->getPosition().y + this->getGlobalBounds().height >= 715)
		{
			Paddle::obstableDown = true;
			Paddle::obstableUp = false;
		}
		if (this->getPosition().y / 2 <= 5)
		{
			Paddle::obstableDown = false;
			Paddle::obstableUp = true;
		}
		if(Paddle::obstableDown == true)
			this->move(0, -velocityObstacle);
		if (Paddle::obstableUp == true)
			this->move(0, velocityObstacle);
		break;

	}
	this->move(this->velocityPaddle);

	if (this->getPosition().y < 0)
		this->move(0, 1.0f);
	if (this->getPosition().y + this->getGlobalBounds().height > 720)
		this->move(0, -1.0f);
}
