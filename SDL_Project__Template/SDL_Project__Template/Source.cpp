#include <SDL.h>
#include <iostream>


#include "Game.h"

int main(int argc, char* argv[])
{
	Game* gameLoop = new Game;

	if (gameLoop != nullptr)
	{
		gameLoop->GameLoop();

		delete gameLoop;
	}
	else
	{
		std::cout << "Failed to Create Game... " << std::endl;
	}
	

	return 0;
}