#include <iostream>
#include "MainMenu.h"
#include "MainGame.h"
#define isAI 0
#define isPlayer 1
using namespace sf;
int gameMode;
void MainMenu::Initialize(RenderWindow* window)
{
	this->selected = 0;
	
	this->font = new Font();
	this->font->loadFromFile("Fonts/visitor1.ttf");

	this->title = new Text("Nathan's Pong", *this->font, 128U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 4);

	this->playWithAI = new Text(">Play With AI", *this->font, 64U);
	this->playWithAI->setOrigin(this->title->getGlobalBounds().width / 4, this->title->getGlobalBounds().height / 2);
	this->playWithAI->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->playWithPlayer = new Text(">2 Players", *this->font, 64U);
	this->playWithPlayer->setOrigin(this->title->getGlobalBounds().width / 4, this->title->getGlobalBounds().height / 2);
	this->playWithPlayer->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 50);

	this->quit = new Text(">Quit", *this->font, 64U);
	this->quit->setOrigin(this->title->getGlobalBounds().width / 4, this->title->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + 100);

}
void MainMenu::Update(RenderWindow* window)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !this->upKey)
		this->selected -= 1;
	if (Keyboard::isKeyPressed(Keyboard::Key::Down) && !this->downKey)
		this->selected += 1;

	if (this->selected > 2)
		this->selected = 0;
	if (this->selected < 0)
		this->selected = 2;

	if (Keyboard::isKeyPressed(Keyboard::Key::Return))
	{
		switch (this->selected)
		{
		case 0:
			gameMode = isAI;
			_currentState.SetState(new MainGame());	
			break;
		case 1:
			gameMode = isPlayer;
			_currentState.SetState(new MainGame());			
			break;
		case 2:
			quitGame = true;
			break;
		}
	}

	this->upKey = Keyboard::isKeyPressed(Keyboard::Key::Up);
	this->downKey = Keyboard::isKeyPressed(Keyboard::Key::Down);
}
void MainMenu::Render(RenderWindow* window)
{
	this->playWithAI->setFillColor(Color::White);
	this->playWithPlayer->setFillColor(Color::White);
	this->quit->setFillColor(Color::White);

	switch (this->selected)
	{
	case 0: 
		this->playWithAI->setFillColor(Color::Yellow);
		break;
	case 1:
		this->playWithPlayer->setFillColor(Color::Yellow);
		break;
	case 2:
		this->quit->setFillColor(Color::Yellow);
		break;
	}
	window->draw(*this->title);
	window->draw(*this->playWithAI);
	window->draw(*this->playWithPlayer);
	window->draw(*this->quit);
}
void MainMenu::Destroy(RenderWindow* window)
{
	delete this->font;
	delete this->title;
	delete this->playWithAI;
	delete this->playWithPlayer;
	delete this->quit;
}

