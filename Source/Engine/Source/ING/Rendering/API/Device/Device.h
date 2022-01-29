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



namespace ING {

	namespace Rendering {

		class DeviceContext;

		class SwapChain;



		class ING_API Device
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Device();
			~Device();



			/**
			 *	Create, Release Methods
			 */
		public:
			static  Device*	Create();
			virtual void	Release();



			/**
			 *	Device Context
			 */
		protected:
			DeviceContext* context;

		public:
			DeviceContext* GetContext() { return context; }

		};

	}

}