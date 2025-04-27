#pragma once

#include <SDL.h>

//Class which deals with all the SQL set up, clean up and houses the Game Loop

class Game
{
	private:

		//WINDOW DIMENSIONS

		int SCREEN_WIDTH = 1080;

		int SCREEN_HEIGHT = 720;



		SDL_Window* window; //The window being rendered to

		SDL_Renderer* renderer; //The renderer which renders to the window

		bool InitiliseGame();

		void CleanUpGame();

	public:

		Game(); //CTOR

		~Game(); //DTOR

		void GameLoop();

		void ClearScreen();


};