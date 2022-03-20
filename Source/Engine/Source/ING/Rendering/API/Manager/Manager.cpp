
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Configuration
 */
#include <ING//Configuration/Configuration.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include API
 */
#include <ING\Rendering/API/API.h>



/**
 *	Include APIs
 */
#include <ING\Rendering/API/DirectX11/API.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		APIManager::APIManager() {

			Debug::Log("Start Creating Rendering::APIManager");

			/* Setup Configuration */
			if (!Application::GetInstance()->GetConfiguration()->Exist("ING::Rendering::APIManager::apiFlag")) {

				Application::GetInstance()->GetConfiguration()->Add<APIFlag>("ING::Rendering::APIManager::apiFlag");

				Application::GetInstance()->GetConfiguration()->Set<APIFlag>("ING::Rendering::APIManager::apiFlag", DIRECTX11_API_FLAG);

			}

			Debug::Log("Rendering::APIManager Created");

		}

		APIManager::~APIManager() {



		}



		/**
		 *	Init, Init API, Run, Release Methods
		 */
		bool APIManager::Init() {

			Debug::Log("Start Initializing Rendering::APIManager");

			apiFlag = Application::GetInstance()->GetConfiguration()->Get<APIFlag>("ING::Rendering::APIManager::apiFlag");

			if (!InitAPI()) {

				Debug::Log("Cant Init Rendering API");
				Debug::Log("Cant Init Rendering::APIManager");

				return false;

			}

			Debug::Log("Rendering::APIManager Initialized");

			return true;
		}

		bool APIManager::InitAPI() {

			switch (apiFlag)
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				api = new DirectX11::API();

				api->Init();

				return true;

				break;

			default:
				break;

			}

			return false;

		}

		bool APIManager::Run() {

			Debug::Log("Start Running Rendering::APIManager");

			return true;
		}

		bool APIManager::Release() {

			Debug::Log("Start Releasing Rendering::APIManager");

			if (api != nullptr) {

				api->Release();

			}

			delete this;

			Debug::Log("Finished Releasing Rendering::APIManager");

			return true;

		}		

	}
}
