
/**
 *	Include Header
 */
#include "Actor.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IActor::IActor() :
		id(0)
	{



	}

	IActor::~IActor()
	{



	}



	/**
	 *	Release Methods
	 */
	void IActor::Release()
	{

		delete this;
	}

}