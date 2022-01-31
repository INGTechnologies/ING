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

	class Thread;



	class ING_API Waiter {

		/**
		 *	Constructors And Destructor
		 */
	public:
		Waiter();
		~Waiter();



	};


}