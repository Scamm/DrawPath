#ifndef __DP_IMAGE_LOADER_HPP__
#define __DP_IMAGE_LOADER_HPP__

#include <string>
#include "SDL.h"

namespace dp {
	class ImageLoader {
		public:
			ImageLoader(const std::string& filepath);
			~ImageLoader();
			SDL_Surface* loadImage();
		private:
			std::string m_filepath;
	};
}

#endif