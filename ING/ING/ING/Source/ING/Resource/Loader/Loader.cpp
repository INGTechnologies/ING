
/**
 *	Include Header
 */
#include "Loader.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Coder
 */
#include <ING/Coder/Coder.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ResourceLoader::ResourceLoader() {



	}

	ResourceLoader::~ResourceLoader() {



	}



	/**
	 *	Release Method
	 */
	void ResourceLoader::Release() {

		delete this;

	}



	/**
	 *	Loade Method
	 */
	Resource* ResourceLoader::Load(std::wstring path, CoderOption& coderOption) {

		return nullptr;

	}

}