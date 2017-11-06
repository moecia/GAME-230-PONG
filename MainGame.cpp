#include <SFML/Window.hpp>
#include "GameState.h"
#include "MainMenu.h"
#include <iostream>
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

	this->player1 = new Paddle_Player(0);
	this->player2 = new Paddle_AI(1);
	this->player1->setPosition(0, window->getSize().y / 2 - this->player2->getGlobalBounds().height / 2);
	this->player2->setPosition(window->getSize().x - this->player2->getGlobalBounds().width, window->getSize().y / 2 - this->player2->getGlobalBounds().height / 2);

	this->ball = new Ball(this->score1, this->score2, this->player1, this->player2);
	this->player2->SetBallPos(this->ball);
	this->ball->Reset(window);
}
void MainGame::Update(RenderWindow* window)
{
	this->ball->Update(window);
	this->player1->Update();
	this->player2->Update();
	this->score1->Update();
	this->score2->Update();
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		_currentState.SetState(new MainMenu());
}
void MainGame::Render(RenderWindow* window)
{
	window->draw(*this->player1);
	window->draw(*this->player2);
	window->draw(*this->ball);
	window->draw(*this->score1);
	window->draw(*this->score2);
}
void MainGame::Destroy(RenderWindow* window)
{
	delete this->player1;
	delete this->player2;
	delete this->ball;
	delete this->score1;
	delete this->score2;
	delete this->font;
}

