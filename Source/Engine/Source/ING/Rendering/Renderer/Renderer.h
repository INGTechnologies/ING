#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	namespace Rendering {

		class ING_API Renderer
		{
			/**
			 *	Constructors And Destructor
			 */
		public:
			Renderer	();
			~Renderer	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}