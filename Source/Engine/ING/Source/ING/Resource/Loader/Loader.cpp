
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
	IResourceLoader::IResourceLoader() {



	}

	IResourceLoader::~IResourceLoader() {



	}



	/**
	 *	Release Method
	 */
	void IResourceLoader::Release() {

		delete this;

	}



	/**
	 *	Loade Method
	 */
	IResource* IResourceLoader::Load(const std::wstring& path, CoderOption& coderOption) {

		return nullptr;

	}

}