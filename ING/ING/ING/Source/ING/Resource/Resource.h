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

	class Loader;



	class ING_API Resource {

		/**
		 *	Constructors And Destructor
		 */
	public:
		Resource();
		~Resource();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();

	};


}