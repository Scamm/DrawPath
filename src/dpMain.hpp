#ifndef __DBMAIN_HPP__
#define __DBMAIN_HPP__
#include <memory>
#include "platform/dpWindow.hpp"

namespace dp {

	class Main {
		public:
			Main();
			~Main();
			bool init();
			void run();
			static void shutdown();
		private:
			Window* m_window;
			static bool m_running;
	};
}

#endif // !__DBMAIN_HPP__
