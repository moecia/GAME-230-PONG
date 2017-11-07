#include "Score.h"
using namespace std;

Score::Score(Font &font, unsigned int size) : Text("Score: 0", font, size)
{
	this->value = 0;
	this->bufferScore = new SoundBuffer;
	this->bufferScore->loadFromFile("Sounds/GetScore.wav");
	this->soundScore = new Sound(*this->bufferScore);
}

void Score::AddScore()
{
	this->soundScore->play();
	this->value += 1;
}

void Score::Update()
{ 
	this->setString("Score: " + to_string(this->value));
}