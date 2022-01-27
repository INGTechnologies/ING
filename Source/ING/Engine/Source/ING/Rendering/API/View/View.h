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

		};

	}

}