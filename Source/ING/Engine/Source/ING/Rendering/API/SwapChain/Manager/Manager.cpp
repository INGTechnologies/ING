
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
 *	Include SwapChain
 */
#include <ING\Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Window Manager
 */
#include <ING/Window/Manager/Manager.h>



/**
 *	Include Rendering API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		SwapChainManager::SwapChainManager() {



		}

		SwapChainManager::~SwapChainManager() {



		}



		/**
		 *	Init, Init API, Run, Release Methods
		 */
		bool SwapChainManager::Init() {

			std::map<HWND, Window*>& windowMap = WindowManager::GetInstance()->GetWindowMap();

			for (auto& item : windowMap) {

				Window* window = item.second;

				Device* device = APIManager::GetInstance()->GetAPI()->GetDevice();

				SwapChain* swapChain = SwapChain::Create(device, window);

			}

			return true;
		}

		bool SwapChainManager::Run() {



			return true;
		}

		bool SwapChainManager::Release() {

			swapChainList.Foreach([](SwapChain*& item) {
				
				item->Release();
				
			});
			
			delete this;

			return true;
		}



		/**
		 *	SwapChain Management
		 */
		void SwapChainManager::AddSwapChain		(SwapChain* swapChain) {

			List<SwapChain*>::Node* node = swapChainList.Add(swapChain);

			swapChain->node = node;

		}

		void SwapChainManager::RemoveSwapChain	(List<SwapChain*>::Node* node) {

			swapChainList.Remove(node);

		}
	}
}
