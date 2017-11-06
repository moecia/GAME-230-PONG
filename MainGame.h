#pragma once
#include "GameState.h"
#include "Entity.h"
#include "Paddle_Player.h"
#include "Ball.h"
#include "Score.h"
#include "Paddle_AI.h"
using namespace sf;
class MainGame : public State
{
public:
	void Initialize(RenderWindow* window);
	void Update(RenderWindow* window);
	void Render(RenderWindow* window);
	void Destroy(RenderWindow* window);
private:
	Paddle_Player* player1;
	Paddle_AI* player2;
	//Paddle_AI* playerAI;
	Ball* ball;
	Score* score1;
	Score* score2;

	Font* font;
};
extern int gameMode;
