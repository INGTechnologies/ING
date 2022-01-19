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

		class ING_API API
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			API();
			~API();



			/**
			 *	Init, Release Methods
			 */
		public:
			virtual bool Init();
			virtual bool Release();

		};

	}

}