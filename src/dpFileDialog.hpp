#ifndef __DP_FILEDIALOG_HPP__
#define __DP_FILEDIALOG_HPP__

#include "dpTypeDefs.hpp"
#include <string>

namespace dp {

	class FileDialog {
		public:
			FileDialog();
			~FileDialog();
			void open();
			void save();

			i8 test();

		private:
			std::string m_filename;
	};

}

#endif
