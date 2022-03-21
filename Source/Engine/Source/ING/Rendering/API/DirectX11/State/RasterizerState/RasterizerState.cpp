
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
 *	Include DirectX11 Convertor
 */
#include <ING/Rendering/API/DirectX11/Convertor/Convertor.h>



/**
 *	Include DirectX11 Device
 */
#include <ING/Rendering/API/DirectX11/Device/Device.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			/**
			 *	Constructors And Destructor
			 */
			RasterizerState::RasterizerState(IDevice* device, const std::string& name, const RasterizerStateDesc& desc) :
				IRasterizerState(device, name, desc)
			{

				D3D11_RASTERIZER_DESC d3ddesc;

				d3ddesc.FillMode = Convertor::GetInstance()->FillMode(desc.fillMode);
				d3ddesc.CullMode = Convertor::GetInstance()->CullMode(desc.cullMode);
				d3ddesc.FrontCounterClockwise = desc.frontCounterClockwise;
				d3ddesc.DepthBias = desc.depthBias;
				d3ddesc.DepthBiasClamp = desc.depthBiasClamp;
				d3ddesc.SlopeScaledDepthBias = desc.slopeScaledDepthBias;
				d3ddesc.DepthClipEnable = desc.depthClipEnable;
				d3ddesc.ScissorEnable = desc.scissorEnable;
				d3ddesc.MultisampleEnable = desc.multisampleEnable;
				d3ddesc.AntialiasedLineEnable = desc.antialiasedLineEnable;

				ID3D11Device* d3d11Device = device->As<DirectX11::Device>()->GetD3D11Device();

				HRESULT hr = d3d11Device->CreateRasterizerState(&d3ddesc, &d3d11RSState);

			}

			RasterizerState::RasterizerState(const std::string& name, const RasterizerStateDesc& desc) : RasterizerState(IAPI::GetInstance()->GetDevice(), name, desc)
			{}

			RasterizerState::~RasterizerState() {



			}



			/**
			 *	Release Methods
			 */
			void RasterizerState::Release() {

				if(d3d11RSState != nullptr)
					d3d11RSState->Release();

				IRasterizerState::Release();

			}

		}

	}

}