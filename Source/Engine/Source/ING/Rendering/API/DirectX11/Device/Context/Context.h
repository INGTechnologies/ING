#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Rendering Device
 */
#include <ING\Rendering\API\Device\Context/Context.h>



/**
 *	Include D3D11
 */
#include <d3d11.h>



namespace ING {

	namespace Rendering {

		class RenderTargetView;



		namespace DirectX11 {

			class ING_API DeviceContext : public Rendering::DeviceContext
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				DeviceContext(Rendering::Device* device);
				~DeviceContext();



				/**
				 *	Release Methods
				 */
			public:
				virtual void	Release() override;



				/**
				 *	Properties
				 */
			private:
				ID3D11DeviceContext* d3d11DeviceContext;

			public:
				ID3D11DeviceContext* GetD3D11DeviceContext() { return d3d11DeviceContext; }



				/**
				 *	Methods
				 */
			public:
				virtual void ClearRenderTargetView(Rendering::RenderTargetView* rtv, Color color) override;

			};

		}

	}

}