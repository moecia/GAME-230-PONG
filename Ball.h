#pragma once
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include "Score.h"
using namespace sf;
using namespace std;
class Ball : public Entity
{
public:
	Vector2f ballAngle;
	float ballVelocity;
	virtual void Update(sf::RenderWindow* window);
	Ball(Score* score1, Score* score2, Paddle* player1, Paddle* player2, Paddle* obstacle, int ballIndex); // Ball index: 0 for Original ball, 1 for Generated ball
	void Reset(RenderWindow* window);
	void AddBall2(RenderWindow* window, int direction);
	~Ball();
private:
	Score* score1;
	Score* score2;
	Paddle* player1;
	Paddle* player2;
	Paddle* obstacle;
	SoundBuffer* bufferWall;
	SoundBuffer* bufferPaddle;
	Sound* soundWall;
	Sound* soundPaddle;
	int ballIndex;
};