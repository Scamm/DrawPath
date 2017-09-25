#include "dpWindow.hpp"
#include "dpDebugLog.hpp"
#include "dpAppDefs.hpp"


#include <sstream>

namespace dp {

	Window::Window() : 
		m_window(nullptr),
		m_mouseFocus(false),
		m_keyboardFocus(false),
		m_fullScreen(false),
		m_minimized(false), 
		m_width(0),
		m_height(0) {
	}

	Window::~Window() {
	}
	
	bool Window::init() { 

		m_window = SDL_CreateWindow(
			DB_APPNAME,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			DB_DEFAULT_SCREEN_W,
			DB_DEFAULT_SCREEN_H,
			SDL_WINDOW_SHOWN);

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		return (m_window != nullptr) && (m_renderer != nullptr);
	}
	

	void Window::uninit() {
		SDL_DestroyWindow(m_window);
	}

	SDL_Renderer* Window::getRenderer() {
		return m_renderer;
	}

	void Window::handleEvent(SDL_Event& e) {
		//Window event occured
		if (e.type == SDL_WINDOWEVENT) {
			//Caption update flag
			bool updateCaption = false;
				switch (e.window.event) {
					//Get new dimensions and repaint on window size change
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						m_width = e.window.data1;
						m_height = e.window.data2;
						SDL_RenderPresent(m_renderer);
						break;
					//Repaint on exposure
					case SDL_WINDOWEVENT_EXPOSED:
						SDL_RenderPresent(m_renderer);
						break;
					//Mouse entered window
					case SDL_WINDOWEVENT_ENTER:
						m_mouseFocus = true;
						updateCaption = true;
						break;
					//Mouse left window
					case SDL_WINDOWEVENT_LEAVE:
						m_mouseFocus = false;
						updateCaption = true;
						break;
					//Window has keyboard focus
					case SDL_WINDOWEVENT_FOCUS_GAINED:
						m_keyboardFocus = true;
						updateCaption = true;
						break;
					//Window lost keyboard focus
					case SDL_WINDOWEVENT_FOCUS_LOST:
						m_keyboardFocus = false;
						updateCaption = true;
						break;
					//Window minimized
					case SDL_WINDOWEVENT_MINIMIZED:
						m_minimized = true;
						break;
					//Window maxized
					case SDL_WINDOWEVENT_MAXIMIZED:
						m_minimized = false;
						break;
					//Window restored
					case SDL_WINDOWEVENT_RESTORED:
						m_minimized = false;
						break;
					}
				//Update window caption with new data
				if (updateCaption) {
					std::stringstream caption;
					caption << "SDL Tutorial - MouseFocus:" << ((m_mouseFocus) ? "On" : "Off") << " KeyboardFocus:" << ((m_keyboardFocus) ? "On" : "Off");
					SDL_SetWindowTitle(m_window, caption.str().c_str());
				}
		}
		//Enter exit full screen on return key
		else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
			if (m_fullScreen) {
				SDL_SetWindowFullscreen(m_window, SDL_FALSE);
				m_fullScreen = false;
			}
			else {
				SDL_SetWindowFullscreen(m_window, SDL_TRUE);
				m_fullScreen = true;
				m_minimized = false;
			}
		}
	}

	i32 Window::getWidth() {
		return m_width;
	}

	i32 Window::getHeight() {
		return m_height;
	}

	bool Window::hasMouseFocus() {
		return m_mouseFocus;
	}

	bool Window::hasKeyboardFocus() {
		return m_keyboardFocus;
	}

	bool Window::isMinimized() {
		return m_minimized;
	}

	
	/*void Window::update() {
		SDL_Surface* s = SDL_GetWindowSurface(m_window);
		SDL_FillRect(s, &s->clip_rect, 0xffff00ff);


		SDL_UpdateWindowSurface(m_window);
	}*/


}