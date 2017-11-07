#include "Ball.h"
#include <iostream>
#include <math.h>

Ball::Ball(Score* score1, Score* score2, Paddle* player1, Paddle* player2, Paddle* obstacle, int ballIndex)
{
	this->Load("Ball.PNG");
	this->setScale(.2f,.2f);
	this->ballIndex = ballIndex;
	this->score1 = score1;
	this->score2 = score2;
	this->player1 = player1;
	this->player2 = player2;
	this->obstacle = obstacle;

	this->bufferWall = new SoundBuffer;
	this->bufferPaddle = new SoundBuffer;
	this->bufferWall->loadFromFile("Sounds/wall_bounce.wav");
	this->bufferPaddle->loadFromFile("Sounds/paddle_bounce.wav");
	this->soundWall = new Sound(*this->bufferWall);
	this->soundPaddle = new Sound(*this->bufferPaddle);
}
void Ball::Update(sf::RenderWindow* window)
{
	if (this->CheckCollision(this->player1))
	{
		this->soundPaddle->play();
		this->ballVelocity += 0.25f;
		this->ballAngle.x *= -1;
		std::cout << this->getPosition().y - this->player1->getPosition().y << endl;
		if (this->player1->getPosition().y > this->getPosition().y)
			this->ballAngle.y = -0.1f * abs(this->getPosition().y - this->player1->getPosition().y) / this->player1->getGlobalBounds().height;
		if (this->player1->getPosition().y < this->getPosition().y)
			this->ballAngle.y = 0.1f * abs(this->getPosition().y - this->player1->getPosition().y) / this->player1->getGlobalBounds().height;
	}
	if (this->CheckCollision(this->player2))
	{
		this->soundPaddle->play();
		this->ballVelocity += 0.25f;
		this->ballAngle.x *= -1;
		this->ballAngle.y = -0.1f * abs(this->getPosition().y - this->player2->getPosition().y) / this->player2->getGlobalBounds().height;
		if (this->player2->getPosition().y > this->getPosition().y)
			this->ballAngle.y = -0.1f * abs(this->getPosition().y - this->player2->getPosition().y) / this->player2->getGlobalBounds().height;
		if (this->player1->getPosition().y < this->getPosition().y)
			this->ballAngle.y = 0.1f * abs(this->getPosition().y - this->player2->getPosition().y) / this->player2->getGlobalBounds().height;
	}

	if (this->CheckCollision(this->obstacle))
	{
		this->soundPaddle->play();
		if(this->getPosition().x < this->obstacle->getPosition().x)
			this->ballAngle.x = -0.1f;
		if (this->getPosition().x > this->obstacle->getPosition().x)
			this->ballAngle.x = 0.1f;
		this->ballAngle.y = -0.1f * abs(this->getPosition().y - this->obstacle->getPosition().y) / this->obstacle->getGlobalBounds().height;
		if (this->player2->getPosition().y > this->getPosition().y)
			this->ballAngle.y = -0.1f * abs(this->getPosition().y - this->obstacle->getPosition().y) / this->obstacle->getGlobalBounds().height;
		if (this->player1->getPosition().y < this->getPosition().y)
			this->ballAngle.y = 0.1f * abs(this->getPosition().y - this->obstacle->getPosition().y) / this->obstacle->getGlobalBounds().height;
	}
	// Collide to the bounds
	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > 720)
	{
		this->ballAngle.y *= -1;
		this->soundWall->play();
	}
	// Add score, Reset the ball.
	if (this->getPosition().x < this->player1->getGlobalBounds().width - 5)
	{
		this->score1->AddScore();
		this->Reset(window);
	}

	if (this->getPosition().x > window->getSize().x - this->player2->getGlobalBounds().width + 5)
	{
		this->score2->AddScore();
		this->Reset(window);			
	}
	// Ball movement
	this->move(this->ballAngle*ballVelocity);
}

void Ball::Reset(RenderWindow* window)
{
	this->ballAngle.x = -(std::rand() % 2 + 1) / 10.0f;
	this->ballAngle.y = -(std::rand() % 1 + 1) / 10.0f;
	this->ballVelocity = 1.0f;
	this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
	this->obstacle->setPosition((window->getSize().x - this->player2->getGlobalBounds().width) / 2, 0);
}

void Ball::AddBall2(RenderWindow* window, int direction)
{
	if (direction == 0) // Left
	{
		ballAngle.x = -0.1f;
		this->ballAngle.y = -0.1f;
	}
	if (direction == 1) // Right
	{
		ballAngle.x = 0.1f;
		this->ballAngle.y = 0.1f;
	}
	this->setColor(Color::Red);
	this->ballVelocity = 2.5f;
	this->setPosition(window->getSize().x / 3, window->getSize().y / 2);
	this->obstacle->setPosition((window->getSize().x - this->player2->getGlobalBounds().width) / 2, 0);
}

Ball::~Ball()
{
	delete this->soundWall;
	delete this->bufferWall;
	delete this->soundPaddle;
	delete this->bufferPaddle;
}