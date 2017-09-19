//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <memory>

#include "dpMain.hpp"
#include "platform/dpWindow.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

namespace dp {
	SDL_Window* sdlWnd;

	bool Main::m_running = true;

	Main::Main() {}
	
	Main::~Main() {}

	bool Main::init() {
		m_window = new Window();
		if (!m_window->create()) {
			m_running = false;
			
		}
		m_window->show();

		SDL_InitSubSystem(SDL_INIT_VIDEO);
		sdlWnd = SDL_CreateWindowFrom(m_window->getHandle());
		SDL_SetWindowTitle(sdlWnd, "SDL Window - Set by SDL");
		
		//SDL_UpdateWindowSurface(sdlWnd);


		return m_running;
	}

	void Main::run() {
		while (m_running) {
			m_window->update();

			SDL_Surface* s = SDL_GetWindowSurface(sdlWnd);
			SDL_FillRect(s, &s->clip_rect, 0xffff00ff);
			SDL_UpdateWindowSurface(sdlWnd);
		}
	}

	void Main::shutdown() {
		m_running = false;
	}
}

int main(int argc, char* argv[])
{
	dp::Main dp;
	dp.init();
	dp.run();

	/*
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
	*/

	return 0;
}