#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Score : public Text
{
public:
	Score(Font &font, unsigned int size);
	void AddScore();
	void Update();
private:
	int value;
};