#include "Core.hpp"

int main( void )
{
	Window		window;

	while (window.IsOpen())
	{
		sf::Event event;
		while (window.HandleEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.Destroy();
		}
		window.Clear();
		window.Render();
	}

	return (0);
}