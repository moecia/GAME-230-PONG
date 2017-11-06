#include "Paddle_Player.h"

Paddle_Player::Paddle_Player(int playerNum)
{
	this->setScale(1.0f, .7f);
	this->plyarNum = playerNum;
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
void Paddle_Player::Update()
{
	switch (this->plyarNum)
	{
	case 0:
		this->velocity.y = (Keyboard::isKeyPressed(Keyboard::Key::S) - Keyboard::isKeyPressed(Keyboard::Key::W)) / velocityControl;
		break;
	default:
		this->velocity.y = (Keyboard::isKeyPressed(Keyboard::Key::Down) - Keyboard::isKeyPressed(Keyboard::Key::Up)) / velocityControl;
		break;

	}
	Entity::Update();

	if (this->getPosition().y < 0)
		this->move(0, 1.0f);
	if (this->getPosition().y + this->getGlobalBounds().height > 720)
		this->move(0, -1.0f);
}