#pragma once

#include <SDL.h>

class Box
{
	public:

		Box(SDL_Renderer* _renderer, int _x, int _y, int _w, int _h, SDL_Color _color); //CTOR

		~Box(); //DTOR


		//SETTERS

		void SetX(int _x) { position.x = _x; }
		void SetY(int _y) { position.y = _y; }

		void SetColor(SDL_Color _color) { color = _color; }


		//GETTERS

		int GetX() { return position.x; }
		int GetY() { return position.y; }
		int GetW() { return position.w; }
		int GetH() { return position.h; }

		SDL_Rect& GetRect() { return position; }



		//METHODS

		void DisplayBox();

		void MoveBox();

	private:

		SDL_Renderer* renderer; //THE RENDERER USED FOR DRAWING

		SDL_Rect position;

		SDL_Color color;





};


