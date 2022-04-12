
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
 *	Include FormatManager
 */
#include <ING\Rendering/API/Format\Manager\Manager.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		APIManager::APIManager() :
			api(0)
		{

			Debug::Log("Start Creating Rendering::APIManager");

			/* Setup Configuration */
			if (!Application::GetInstance()->GetConfiguration()->Exist("ING::Rendering::APIManager::apiFlag")) {

				Application::GetInstance()->GetConfiguration()->Add<APIFlag>("ING::Rendering::APIManager::apiFlag");

				Application::GetInstance()->GetConfiguration()->Set<APIFlag>("ING::Rendering::APIManager::apiFlag", DIRECTX11_API_FLAG);

			}

			AddSquare<FormatManager>();

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

				Debug::Error("Cant Init Rendering::API");
				Debug::Error("Cant Init Rendering::APIManager");

				return false;

			}

			bool result = Board<APIManager>::Init();

			if (result) {

				Debug::Log("Rendering::APIManager Initialized");

			}
			else {

				Debug::Error("Cant Init Rendering::APIManager");

			}

			return result;
		}

		bool APIManager::InitAPI() {

			switch (apiFlag)
			{

			case NONE_API_FLAG:

				Debug::Error("No Rendering::API Choosed");

				return false;

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

			return Board<APIManager>::Run();
		}

		bool APIManager::Release() {

			Debug::Log("Start Releasing Rendering::APIManager");

			if (api != nullptr) {

				api->Release();

			}

			bool result = Board<APIManager>::Release();

			if (result) {

				Debug::Log("Finished Releasing Rendering::APIManager");

			}
			else {

				Debug::Error("Cant Release Rendering::APIManager");

			}

			return true;

		}		

	}
}
