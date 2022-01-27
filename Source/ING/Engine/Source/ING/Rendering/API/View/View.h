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



		class ING_API View
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			View();
			~View();



			/**
			 *	Create, Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Resource
			 */
		private:
			Resource* resource;

		public:
			Resource*	GetResource	() { return resource; }
			
			void		SetResource	(Resource* resource) { this->resource = resource; }

		};

	}

}