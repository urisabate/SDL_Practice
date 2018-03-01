//using SDL and IO
#include <iostream>
#include <cstdio>
#include <cmath>
#include "SDL\include\SDL.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")

#define PI 3.14159

using namespace std;

//Screen diemnsion constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[])
{
	//starting SDL
	SDL_Init(SDL_INIT_VIDEO);

	//creating window
	SDL_Window* window = SDL_CreateWindow("SDLGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

	//creating renderer
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool run = true;
	SDL_Event event;
	while (run)
	{
		//events...
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				run = false;
			}
		}
		for (int i = 0; i < 400; i++)
		{
			//painting screen
			SDL_SetRenderDrawColor(renderer, 0, 125, 255, 255);
			SDL_RenderClear(renderer);

			//Drawing rectangle
			int x = 0 + i, y = (SCREEN_HEIGHT / 2) + (cos(i / PI * 180)*100);
			SDL_SetRenderDrawColor(renderer, 255,0, 0, 255);
			SDL_Rect rect = { x,y,100,100 };
			SDL_RenderFillRect(renderer, &rect);

			//showing drawn
			SDL_RenderPresent(renderer);
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}