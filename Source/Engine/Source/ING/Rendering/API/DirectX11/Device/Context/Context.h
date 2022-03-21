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

		namespace DirectX11 {

			class ING_API DeviceContext : public IDeviceContext
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				DeviceContext(IDevice* device);
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
				virtual void IASetInputLayout		(IInputLayout* inputLayout) override;
				virtual void IASetPrimitiveTopology	(PrimitiveTopology primitiveTopology);
				virtual void IASetVertexBuffers		(const std::vector<IBuffer*>& buffers) override;
				virtual void IASetVertexBuffer		(IBuffer* buffer, unsigned int stride, unsigned int offset) override;
				virtual void IASetIndexBuffer		(IBuffer* buffer, Format format, unsigned int offset) override;

				virtual void OMSetRenderTargets		(const std::vector<IRenderTargetView*>& rtvs, IDepthStencilVIew* dsv) override;
				virtual void OMSetRenderTargets		(IRenderTargetView* rtv, IDepthStencilVIew* dsv) override;

				virtual void VSSetShader			(IVertexShader* vertexShader) override;
				virtual void PSSetShader			(IPixelShader* pixelShader) override;

				virtual void DrawIndexed			(unsigned int indexCount, unsigned int startIndexLocation, int baseVertexLocation) override;

			};

		}

	}

}