#include "dpAppDefs.hpp"
#include "dpMain.hpp"
#include "dpWindow.hpp"
#include "dpDebugLog.hpp"
#include "dpFileDialog.hpp"

#include <SDL.h>

namespace dp {

	Main::Main() : m_running(true) {}
	
	Main::~Main() {}

	bool Main::init() {

		if (SDL_Init(SDL_INIT_VIDEO) != 0) {
			LOG("SDL could not be initialized!");
			m_running = false;
		}
		else {
			m_window = std::make_unique<Window>();
			if (!m_window->init()) {
				m_running = false;
			}
		}
		return m_running;
	}

	void Main::uninit() {
		m_window->uninit();
		SDL_Quit();
	}

	void Main::run() {

		SDL_Renderer* renderer = m_window->getRenderer();
		SDL_Event e;

		while (m_running) {

			//Handle events on queue
			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					m_running = false;
				}
				if (e.type == SDL_KEYDOWN)
				{
					SDL_Keycode keyPressed = e.key.keysym.sym;

					switch (keyPressed)
					{
						case SDLK_ESCAPE:
							m_running = false;
							break;
						case SDLK_o: {
							FileDialog d;
							std::string imagepath = d.open();
							if (!imagepath.empty()) {
								//DO STUFF
								LOG("read file into SDL_surface");
							}
							break;
						}
					}
				}
				//Handle window events
				m_window->handleEvent(e);
			}

			//Only draw when not minimized
			if (!m_window->isMinimized()) {
				//Clear screen
				SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
				SDL_RenderClear(renderer);
				//Update screen
				SDL_RenderPresent(renderer);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	dp::Main dp;
	dp.init();
	dp.run();
	dp.uninit();
	return 0;
}