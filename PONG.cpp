#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "GameState.h"
#include "MainMenu.h"

CurrentState _currentState;
bool quitGame = false;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Nathan's PONG");

	_currentState.SetWindow(& window);
	_currentState.SetState(new MainMenu());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::Black);

		_currentState.Update();
		_currentState.Render();
		window.display();
	
		if (quitGame)
			window.close();
	}

	return 0;
}

void Initialize()
{

}
