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

		class IDeviceContext;

		class SwapChain;



		class ING_API IDevice :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IDevice();
			~IDevice();



			/**
			 *	Create, Release Methods
			 */
		public:
			static  IDevice*	Create();
			virtual void		Release();



			/**
			 *	IDevice Context
			 */
		protected:
			IDeviceContext* immediateContext;

		public:
			IDeviceContext* GetImmediateContext() { return immediateContext; }

		};

	}

}