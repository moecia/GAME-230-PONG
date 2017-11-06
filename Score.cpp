#include "Score.h"
using namespace std;

Score::Score(Font &font, unsigned int size) : Text("Score: 0", font, size)
{
	this->value = 0;
}

void Score::AddScore()
{
	this->value += 1;
}

void Score::Update()
{ 
	this->setString("Score: " + to_string(this->value));
}