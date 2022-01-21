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



/**
 *	Include Vector
 */
#include <vector>



namespace ING {

	namespace Rendering {

		class ING_API Shader {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Shader();
			~Shader();

		};

	}

}