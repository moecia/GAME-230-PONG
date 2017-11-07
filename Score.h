#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
class Score : public Text
{
public:
	Score(Font &font, unsigned int size);
	void AddScore();
	void Update(); 
	int value;
private:
	SoundBuffer* bufferScore;
	Sound* soundScore;
};