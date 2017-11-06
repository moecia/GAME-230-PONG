#pragma once
#include "GameState.h"
using namespace sf;
class MainMenu : public State
{
public:
	void Initialize(RenderWindow* window);
	void Update(RenderWindow* window);
	void Render(RenderWindow* window);
	void Destroy(RenderWindow* window);
private:
	Font* font;
	Text* title;
	Text* playWithAI;
	Text* playWithPlayer;
	Text* quit;

	int selected;

	bool upKey, downKey;
};
