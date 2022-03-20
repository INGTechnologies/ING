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

		class IDevice;



		class ING_API IResource :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IResource(IDevice* device);
			~IResource();



			/**
			 *	Create, Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			IDevice* device;

		public:
			IDevice* GetDevice() { return device; }

		};

	}

}