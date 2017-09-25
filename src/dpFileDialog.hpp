#ifndef __DP_FILEDIALOG_HPP__
#define __DP_FILEDIALOG_HPP__

#include "dpTypeDefs.hpp"
#include <string>

#include <vector>
#include <string>

namespace dp {

	class FileDialog {
		public:
			FileDialog();
			~FileDialog();
			std::string open();
			bool save(const std::vector<char>& data);

			i8 test();

		private:
			std::string m_filename;
	};

}

#endif
