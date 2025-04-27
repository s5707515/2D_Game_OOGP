#include <SDL.h>
#include <iostream>

#include "Box.h"

Box::Box(SDL_Renderer* _renderer, int _x, int _y, int _w, int _h, SDL_Color _color)
{
	renderer = _renderer;

	position.x = _x;
	position.y = _y;
	position.w = _w;
	position.h = _h;

	color = _color;
}

Box::~Box()
{
	std::cout << "Box Destroyed " << std::endl;
}

void Box :: DisplayBox()
{
	SDL_SetRenderDrawColor(renderer,color.r, color.g, color.b, color.a);

	SDL_RenderDrawRect(renderer, &position);

}

void Box::MoveBox() //Move box using WASD
{
	//GET KEYBOARD

	const Uint8* key = SDL_GetKeyboardState(NULL);

	//ADD WASD CONTROLS TO MOVE BOX

	if (key[SDL_SCANCODE_W])
	{
		position.y -= 5;
	}

	if (key[SDL_SCANCODE_A])
	{
		position.x -= 5;
	}

	if (key[SDL_SCANCODE_S])
	{
		position.y += 5;
	}

	if (key[SDL_SCANCODE_D])
	{
		position.x += 5;
	}
}

