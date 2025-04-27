#include <SDL.h>
#include <iostream>

#include "Game.h"

#include "Box.h"

Game::Game() //CTOR (Automatically initialises the game)
{
	InitiliseGame();
}

Game::~Game() //DTOR (Cleans up memory on object destruction)
{
	CleanUpGame();
}

void Game::ClearScreen()
{
	SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);

	SDL_RenderClear(renderer);

}

bool Game::InitiliseGame() //Attempts to create the window and renderer
{
	bool success = true;

	//Initialize SDL

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error:" << SDL_GetError() << std::endl;

		system("pause");
		success = false;
	}
	else
	{
		//Create Window

		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			
			system("pause");
			success = false;
		}
		else
		{
			//Create Renderer

			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


			if (renderer == NULL)
			{
				std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;

				system("pause");
				success = false;
			}


		}
	}

	return success;
}

void Game::CleanUpGame() //Frees up any memory used
{
	//Destroy Renderer

	SDL_DestroyRenderer(renderer);

	//Destroy Window

	SDL_DestroyWindow(window);

	//Quit SDL

	SDL_Quit();

	std::cout << "Game was clean up successfully!" << std::endl;
}


void Game::GameLoop() //The actual GameLoop of the game
{
	SDL_Event e;

	bool quit = false;

	SDL_Color boxColor = {200, 10, 150, 255};

	Box* box = new Box(renderer, 515, 335, 50, 50, boxColor);


	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
				case SDL_QUIT:

					quit = true;
					break;

				default:

					break;
			}

		}

		//This is called each frame of the game

		ClearScreen();

		box->MoveBox();

		box->DisplayBox();

		SDL_RenderPresent(renderer);
	}

	delete box;
}


