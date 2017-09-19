#ifndef __DBWINDOW_HPP__
#define __DBWINDOW_HPP__

namespace dp {

	class Window {
		public:
			Window();
			~Window();
			bool create();
			void show();
			void update();
			bool isCreated() { return m_created;  }
			void* getHandle();
			void quit();
		private:
			bool m_created;
	};

}

#endif // !__DBWINDOW_HPP__
