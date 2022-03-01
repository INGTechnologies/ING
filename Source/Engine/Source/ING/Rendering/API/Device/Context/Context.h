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

		class RenderTargetView;

		class Device;



		class ING_API DeviceContext :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			DeviceContext(Device* device);
			~DeviceContext();



			/**
			 *	Create, Release Methods
			 */
		public:
			static  DeviceContext*	Create(Device* device);
			virtual void			Release();



			/**
			 *	Device Context
			 */
		protected:
			Device* device;

		public:
			Device* GetDevice() { return device; }



			/**
			 *	Methods
			 */
		//public:
			//virtual void ClearRenderTargetView(RenderTargetView* rtv, Color color);

		};

	}

}