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

		class Device;

		class ING_API SwapChain
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			SwapChain(Device* device);
			~SwapChain();



			/**
			 *	Create, Release Methods
			 */
		public:
			static  SwapChain*	Create(Device* device);
			virtual void		Release();



			/**
			 *	Device
			 */
		private:
			Device* device;

		public:
			Device* GetDevice() { return device; }

		};

	}

}