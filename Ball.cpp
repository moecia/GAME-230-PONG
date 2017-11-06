#include "Ball.h"

Ball::Ball(Score* score1, Score* score2, Paddle* player1, Paddle* player2)
{
	this->Load("Ball.PNG");
	this->setScale(.3f,.3f);
	this->score1 = score1;
	this->score2 = score2;
	this->player1 = player1;
	this->player2 = player2;

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
		this->velocity.x *= -1;
		this->setPosition(this->player1->getGlobalBounds().width + this->getGlobalBounds().width/2, this->getPosition().y);
		this->soundPaddle->play();
	}
	else if (this->CheckCollision(this->player2))
	{
		this->velocity.x *= -1;
		//this->setPosition(this->player2->getGlobalBounds().width + this->getGlobalBounds().width / 2, this->getGlobalBounds().height);
		this->soundPaddle->play();
	}


	if (this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > 720)
	{
		this->velocity.y *= -1;
		this->soundWall->play();
	}

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
	Entity::Update();
}

void Ball::Reset(RenderWindow* window)
{
	this->velocity.x = -0.1f;
	this->velocity.y = -0.1f;
	this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

Ball::~Ball()
{
	delete this->soundWall;
	delete this->bufferWall;
	delete this->soundPaddle;
	delete this->bufferPaddle;
}