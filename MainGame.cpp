#include <SFML/Window.hpp>
#include "GameState.h"
#include "MainMenu.h"
#include <iostream>
#include <math.h>
#include "MainGame.h"
#include "MainMenu.h"
#include "Score.h"

using namespace sf;
void MainGame::Initialize(RenderWindow* window)
{
	this->font = new Font();
	this->font->loadFromFile("Fonts/visitor1.ttf");
	this->score1 = new Score(*font, 64U);
	this->score2 = new Score(*font, 64U);
	this->score1->setPosition(window->getSize().x - this->score2->getGlobalBounds().width, 0);

	this->bufferWinner = new SoundBuffer;
	this->bufferWinner->loadFromFile("Sounds/Winner.wav");
	this->soundWinner = new Sound(*this->bufferWinner);

	this->player1 = new Paddle(0);
	this->player2 = new Paddle(1);
	this->obstacle = new Paddle(2);
	this->player1->setPosition(0, window->getSize().y / 2 - this->player2->getGlobalBounds().height / 2);
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2 - this->player2->getGlobalBounds().height / 2);
	this->obstacle->setPosition((window->getSize().x - this->player2->getGlobalBounds().width)/2, 0);

	this->ball = new Ball(this->score1, this->score2, this->player1, this->player2, this->obstacle, 0);
	this->ball2 = new Ball(this->score1, this->score2, this->player1, this->player2, this->obstacle, 1);
//	this->player2->SetBallPos(this->ball);
	this->ball->Reset(window);
}
void MainGame::Update(RenderWindow* window)
{
	this->ball->Update(window);
	if (MainGame::ball2Added == true)
		this->ball2->Update(window);
	this->player1->Update(this->ball->getPosition().y, this->ball2->getPosition().y);
	this->player2->Update(this->ball->getPosition().y, this->ball2->getPosition().y);
	this->obstacle->Update(this->ball->getPosition().y, this->ball2->getPosition().y);
	this->score1->Update();
	this->score2->Update();
	this->ShowWinner(window);
	if (abs(this->score1->value -this->score2->value) == 2 && MainGame::ball2Added == false)
	{
		if (this->score1->value > this->score2->value)
			this->ball2->AddBall2(window, 1);
		if (this->score1->value  < this->score2->value)
			this->ball2->AddBall2(window, 0);
		ball2Added = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		_currentState.SetState(new MainMenu());
}
void MainGame::Render(RenderWindow* window)
{
	window->draw(*this->player1);
	window->draw(*this->player2);
	window->draw(*this->obstacle);
	window->draw(*this->ball);
	if (MainGame::ball2Added == true)
	{
		window->draw(*this->ball2);
		if (this->score1->value == this->score2->value)
			MainGame::ball2Added = false;
	}
	window->draw(*this->score1);
	window->draw(*this->score2);
}
void MainGame::Destroy(RenderWindow* window)
{
	delete this->player1;
	delete this->player2;
	delete this->obstacle;
	delete this->ball;
	delete this->ball2;
	delete this->score1;
	delete this->score2;
	delete this->font;
}
void MainGame::ShowWinner(RenderWindow* window)
{
	if (this->score1->value == 5 || this->score2->value == 5)
	{
		Text winner("", *font, 64);
		if (this->score1->value == 5)
			winner.setString("Player 2 Win!");
		if (this->score2->value == 5)
			winner.setString("Player 1 Win!");
		winner.setPosition(window->getSize().x / 3, window->getSize().y / 4);
		window->draw(winner);
		this->ball->ballVelocity = 0;
		this->ball2->ballVelocity = 0;
		if (soundWinner->getStatus()!= SoundSource::Playing)
			soundWinner->play();
		if (Keyboard::isKeyPressed(Keyboard::Key::Space))
		{
			_currentState.SetState(new MainGame());
		}
	}
}

