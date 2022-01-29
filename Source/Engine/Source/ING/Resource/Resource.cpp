
/**
 *	Include Header
 */
#include "Resource.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Resource::Resource() {



	}

	Resource::~Resource() {



	}



	/**
	 *	Release Method
	 */
	void Resource::Release() {

		delete this;

	}

}