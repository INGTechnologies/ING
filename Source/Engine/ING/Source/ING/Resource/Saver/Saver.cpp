
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
	IResourceSaver::IResourceSaver() {



	}

	IResourceSaver::~IResourceSaver() {



	}



	/**
	 *	Release Method
	 */
	void IResourceSaver::Release() {

		delete this;

	}



	/**
	 *	Loader Method
	 */
	void IResourceSaver::Save(IResource* resource, CoderOption& coderOption) {



	}

}