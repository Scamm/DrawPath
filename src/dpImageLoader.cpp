#include "dpImageLoader.hpp"
#include "dpDebugLog.hpp"

#define SDL_STBIMAGE_IMPLEMENTATION
#include "SDL_stbimage.h"


namespace dp {
	ImageLoader::ImageLoader(const std::string& filepath) {
		LOG("IMAGELOADER PARAMETER CTOR");
		m_filepath = filepath;
	}

	ImageLoader::~ImageLoader() {

	}

	SDL_Surface* ImageLoader::loadImage() {

		SDL_Surface* surf = STBIMG_Load(m_filepath.c_str());
		if (surf == NULL) {
			LOG("ERROR: Couldn't load %s, reason: %s\n", m_filepath.c_str(), SDL_GetError());
			return nullptr;
		}
		return surf;

		//Remember to free the surface
		//SDL_FreeSurface(surf);
	}
}