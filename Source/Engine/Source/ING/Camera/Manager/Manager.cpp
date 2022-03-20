
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Camera
 */
#include "../Camera.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	CameraManager::CameraManager() {

		Debug::Log("Start Creating CameraManager");

		Debug::Log("CameraManager Created");

	}

	CameraManager::~CameraManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool CameraManager::Init() {

		Debug::Log("Start Initializing CameraManager");

		Debug::Log("CameraManager Initialized");

		return true;
	}

	bool CameraManager::Run() {

		Debug::Log("Start Running CameraManager");

		return true;
	}

	bool CameraManager::Release() {

		Debug::Log("Start Releasing CameraManager");

		Debug::Log("Finished Releasing CameraManager");

		return Square::Release();
	}



	/**
	 *	Methods
	 */
	List<Camera*>::Node*	CameraManager::AddCamera(Camera* camera) {

		return cameraList.Add(camera);

	}

	void					CameraManager::RemoveCamera(List<Camera*>::Node* node) {

		cameraList.Remove(node);

	}

}
