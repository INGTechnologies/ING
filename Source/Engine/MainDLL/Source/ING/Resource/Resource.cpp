
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
	IResource::IResource() {



	}

	IResource::~IResource() {



	}



	/**
	 *	Release Method
	 */
	void IResource::Release() {

		delete this;

	}

}