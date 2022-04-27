
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



/**
 *	Include Rendering Pipeline
 */
#include <ING/Rendering/Pipeline/Pipeline.h>



/**
 *	Include Rendering SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering CameraData
 */
#include <ING/Rendering/CameraData/CameraData.h>



/**
 *	Include XMath
 */
//#include <ING/XMath/XMathDef.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Camera::Camera() :
		node(0),
		renderingPipeline(0),
		renderingScene(0),
		renderingData(0)
	{

		isActive	= true;

		screen		= ScreenManager::GetInstance()->GetMainScreen();

		oldScreenWidth = screen->GetClientWidth();
		oldScreenHeight = screen->GetClientHeight();

		nodeInScreenCameraList = screen->AddCamera(this);

		node		= CameraManager::GetInstance()->AddCamera(this);

		targetMode  = CAMERA_TARGET_SCREEN;

	}

	Camera::~Camera()
	{



	}



	/**
	 *	Release Methods
	 */
	void Camera::Release()
	{

		if (GetTargetMode() == CAMERA_TARGET_SCREEN)
			screen->RemoveCamera(this);

		renderingData->Release();

		CameraManager::GetInstance()->RemoveCamera(node);

		delete this;

	}



	/**
	 *	Properties
	 */
	void Camera::SetScreen(Screen* screen) {

		if(this->screen != 0)
			this->screen->RemoveCamera(this);

		this->screen = screen;

		if (screen != 0)
			nodeInScreenCameraList = screen->AddCamera(this);

		Update(); 
	}

	void Camera::SetTargetMode(CameraTargetMode mode) {

		if (mode == targetMode) return;

		this->targetMode = mode;

		

	}

	unsigned int Camera::GetClientWidth() {

		if (this->targetMode == CAMERA_TARGET_SCREEN) {

			if (screen != nullptr)
				return screen->GetClientWidth();

		}

		return 0;
	}

	unsigned int Camera::GetClientHeight() {

		if (this->targetMode == CAMERA_TARGET_SCREEN) {

			if (screen != nullptr)
				return screen->GetClientHeight();

		}
		
		return 0;
	}



	/**
	 *	Methods
	 */
	void Camera::Update() {

		/* Check if screen resized */
		if (targetMode == CAMERA_TARGET_SCREEN) {

			if (screen != nullptr) {

				if (oldScreenWidth != screen->GetClientWidth() || oldScreenHeight != screen->GetClientHeight()) {

					Rendering::IDeviceContext* context = screen->GetSwapChain()->GetDevice()->GetImmediateContext();

					renderingPipeline->SetupCamera(context, this);

				}

				oldScreenWidth = screen->GetClientWidth();
				oldScreenHeight = screen->GetClientHeight();

			}
			else {

				if (renderingData == nullptr) {

					delete renderingData;

				}

			}

		}
		else {



		}




		/* Compute View Matrix */




		/* Compute Projection Matrix */
		float aspectRatio = 1.0f;

		if (targetMode == CAMERA_TARGET_SCREEN) {
			if (screen != nullptr) {

				aspectRatio = screen->GetAspectRatio();

			}
		}

		//projectionMatrix = AMath::PerspectiveMatrix(fov, aspectRatio, nearPlane, farPlane);

	}

}