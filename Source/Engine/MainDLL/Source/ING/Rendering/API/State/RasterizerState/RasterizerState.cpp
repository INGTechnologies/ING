
/**
 *	Include Header
 */
#include "RasterizerState.h"



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include DirectX11 Rasterizer State
 */
#include <ING/Rendering/API/DirectX11/State/RasterizerState/RasterizerState.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IRasterizerState::IRasterizerState(IDevice* device, const std::string& name, const RasterizerStateDesc& desc) :
			IState(device, name)
		{

			this->desc = desc;

		}

		IRasterizerState::IRasterizerState(const std::string& name, const RasterizerStateDesc& desc) : IRasterizerState(IAPI::GetInstance()->GetDevice(), name, desc)
		{}

		IRasterizerState::~IRasterizerState() {



		}



		/**
		 *	Methods
		 */
		IRasterizerState* IRasterizerState::Create(IDevice* device, const std::string& name, const RasterizerStateDesc& desc) {

			switch (APIManager::GetInstance()->GetAPIFlag())
			{

			case NONE_API_FLAG:

				break;

			case DIRECTX11_API_FLAG:

				return new DirectX11::RasterizerState(device, name, desc);

				break;

			case DIRECTX12_API_FLAG:

				break;

			case VULKAN_API_FLAG:

				break;

			case OPENGL_API_FLAG:

				break;

			default:
				break;
			}

			return nullptr;

		}
	
		IRasterizerState* IRasterizerState::Create(const std::string& name, const RasterizerStateDesc& desc) {

			return Create(IAPI::GetInstance()->GetDevice(), name, desc);

		}

		void IRasterizerState::Apply() {

			GetDevice()->GetImmediateContext()->RSSetState(this);

		}

	}

}