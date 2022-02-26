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

		class Resource;

		class Device;



		class ING_API View :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			View(Device* device);
			~View();



			/**
			 *	Create, Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			Resource*	resource;

			Device*		device;

		public:
			Resource*	GetResource	()						{ return resource; }
			
			void		SetResource	(Resource* resource)	{ this->resource = resource; }

			Device*		GetDevice	()						{ return device; }

			void		SetDevice	(Device* device)		{ this->device = device; }

		};

	}

}