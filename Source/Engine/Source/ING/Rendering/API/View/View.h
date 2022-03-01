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



		class ING_API IView :
			public AsMethod
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IView	();
			~IView	();



			/**
			 *	Create, Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Resource
			 */
		private:
			IResource* resource;

		public:
			IResource*	GetResource	() { return resource; }
			
			void		SetResource	(IResource* resource) { this->resource = resource; }

		};

	}

}