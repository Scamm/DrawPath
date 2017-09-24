#ifndef __DBWINDOW_HPP__
#define __DBWINDOW_HPP__

#include "dpTypeDefs.hpp"
#include <SDL.h>

namespace dp {

	class Window {
		public:
			Window();
			~Window();
			bool init();
			void uninit();

			//Creates renderer from internal window
			SDL_Renderer* getRenderer();

			//Handles window events
			void handleEvent(SDL_Event& e);

			//void show();
			//void update();
			//void* getHandle();
			
			//Window dimensions
			i32 getWidth();
			i32 getHeight();

			//Window focii
			bool hasMouseFocus();
			bool hasKeyboardFocus();
			bool isMinimized();

		private:
			SDL_Window* m_window;
			SDL_Renderer* m_renderer;
			
			i32	m_width;
			i32 m_height;

			bool m_mouseFocus;
			bool m_keyboardFocus;
			bool m_fullScreen;
			bool m_minimized;
	};

}

#endif // !__DBWINDOW_HPP__
