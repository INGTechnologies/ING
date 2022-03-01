
/**
 *	Include Header
 */
#include "Camera.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Transform
 */
#include <ING/Transform/Transform.h>



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Camera::Camera()
	{

		isActive	= true;

		transformM	= nullptr;

		screen		= ScreenManager::GetInstance()->GetMainScreen();

		node		= CameraManager::GetInstance()->AddCamera(this);

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



	/**
	 *	Methods
	 */
	void Camera::Update() {

		/* Compute View Matrix */
		if (transformM != nullptr) {

			Matrix4x4 nonScaleTransformMatrix = transformM->translationMatrix * transformM->rotationMatrix;

			viewMatrix = nonScaleTransformMatrix.Inverse();

		}
		else {

			viewMatrix = Matrix4x4::Identity();

		}



		/* Compute Projection Matrix */
		float aspectRatio = 1.0f;
		
		if (screen != nullptr) {

			aspectRatio = screen->GetAspectRatio();

		}

		projectionMatrix = Math::ProjectionMatrix(fov, aspectRatio, nearPlane, farPlane);

	}

}