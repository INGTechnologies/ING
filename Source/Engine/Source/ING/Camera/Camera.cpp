
/**
 *	Include Header
 */
#include "Camera.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Camera::Camera()
	{



	}

	Camera::~Camera()
	{



	}



	/**
	 *	Release Methods
	 */
	void Camera::Release()
	{

		delete this;

	}

}