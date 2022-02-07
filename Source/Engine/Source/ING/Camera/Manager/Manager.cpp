
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



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	CameraManager::CameraManager() {



	}

	CameraManager::~CameraManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool CameraManager::Init() {



		return true;
	}

	bool CameraManager::Run() {



		return true;
	}

	bool CameraManager::Release() {



		return Square::Release();
	}

}
