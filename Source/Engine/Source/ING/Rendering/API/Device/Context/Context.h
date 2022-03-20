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
 *	Include Color
 */
#include <ING\Color/Color.h>



namespace ING {

	namespace Rendering {

		class IRenderTargetView;

		class IInputLayout;

		class IDevice;



		class ING_API IDeviceContext :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IDeviceContext(IDevice* device);
			~IDeviceContext();



			/**
			 *	Create, Release Methods
			 */
		public:
			static  IDeviceContext*	Create(IDevice* device);
			virtual void			Release();



			/**
			 *	IDevice Context
			 */
		protected:
			IDevice* device;

		public:
			IDevice* GetIDevice() { return device; }



			/**
			 *	Methods
			 */
		public:
			//virtual void ClearRenderTargetView(RenderTargetView* rtv, Color color);
			virtual void IASetInputLayout(IInputLayout* inputLayout);

		};

	}

}