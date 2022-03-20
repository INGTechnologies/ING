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

		class IResource;

		class IDevice;



		class ING_API IView :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IView	(IDevice* device);
			~IView	();



			/**
			 *	Create, Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			IResource*	resource;

			IDevice*	device;

		public:
			IResource*	GetResource	() { return resource; }
			
			void		SetResource	(IResource* resource) { this->resource = resource; }

			IDevice*	GetDevice() { return device; }

		};

	}

}