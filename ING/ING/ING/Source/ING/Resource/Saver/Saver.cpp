
/**
 *	Include Header
 */
#include "Saver.h"



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
	ResourceSaver::ResourceSaver() {



	}

	ResourceSaver::~ResourceSaver() {



	}



	/**
	 *	Release Method
	 */
	void ResourceSaver::Release() {

		delete this;

	}



	/**
	 *	Loader Method
	 */
	void ResourceSaver::Save(Resource* resource, CoderOption& coderOption) {



	}

}