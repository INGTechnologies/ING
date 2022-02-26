
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

		node = CameraManager::GetInstance()->AddCamera(this);

	}

	Camera::~Camera()
	{



	}



	/**
	 *	Release Methods
	 */
	void Camera::Release()
	{

		CameraManager::GetInstance()->RemoveCamera(node);

		delete this;

	}

}