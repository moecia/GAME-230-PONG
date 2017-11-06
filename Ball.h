#pragma once
#include <SFML/Audio.hpp>
#include "Paddle_Player.h"
#include "Score.h"
using namespace sf;
using namespace std;
class Ball : public Entity
{
public:
	Ball(Score* score1, Score* score2, Paddle* player1, Paddle* player2);
	void Update(sf::RenderWindow* window);
	void Reset(RenderWindow* window);
	~Ball();
private:
	Score* score1;
	Score* score2;
	Paddle* player1;
	Paddle* player2;
	float velocityControl = 5.0f;
	SoundBuffer* bufferWall;
	SoundBuffer* bufferPaddle;
	Sound* soundWall;
	Sound* soundPaddle;
};