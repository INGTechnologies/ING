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
 *	Include Rendering RenderTargetView
 */
#include <ING/Rendering/API/View/RenderTargetView/RenderTargetView.h>



/**
 *	Include D3D11
 */
#include <d3d11.h>



namespace ING {

	namespace Rendering {

		namespace DirectX11 {

			class ING_API RenderTargetView : public Rendering::IRenderTargetView
			{



				/**
				 *	Constructors And Destructor
				 */
			public:
				RenderTargetView();
				~RenderTargetView();



				/**
				 *	Create, Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	D3D11RenderTargetView
				 */
			private:
				ID3D11RenderTargetView* d3d11RenderTargetView;

			public:
				ID3D11RenderTargetView* GetD3D11RenderTargetView() { return d3d11RenderTargetView; }

				void					SetD3D11RenderTargetView(ID3D11RenderTargetView* d3d11RenderTargetView) { 
					
					this->d3d11RenderTargetView = d3d11RenderTargetView; 
				
				}

			};

		}

	}

}