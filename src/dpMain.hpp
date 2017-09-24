#ifndef __DBMAIN_HPP__
#define __DBMAIN_HPP__

#include "dpWindow.hpp"
#include "dpTypeDefs.hpp"
#include <memory>

namespace dp {

	class Main {
		public:
			Main();
			~Main();
			bool init();
			void uninit();

			void run();

		private:
			std::unique_ptr<Window> m_window;
			bool m_running;
	};
}

#endif // !__DBMAIN_HPP__
