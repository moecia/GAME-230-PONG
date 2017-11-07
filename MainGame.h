#pragma once
#ifndef MAINGAME_H
#define MAINGAME_H

#include "GameState.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include "Score.h"
using namespace sf;

class MainGame : public State
{
public:
	void Initialize(RenderWindow* window);
	void Update(RenderWindow* window);
	void Render(RenderWindow* window);
	void Destroy(RenderWindow* window);
	void ShowWinner(RenderWindow* window);
private:
	Paddle* player1;
	Paddle* player2;
	Paddle* obstacle;
	Ball* ball;
	Ball* ball2;
	bool ball2Added = false;
	Score* score1;
	Score* score2;
	Font* font;
	SoundBuffer* bufferWinner;
	Sound* soundWinner;
};
extern int gameMode;


#endif // !MAINGAME_H
