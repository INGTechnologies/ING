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



/**
 *	Include ApplicationThread
 */
#include <ING\Application/Thread/Thread.h>



namespace ING {

	class ING_API ApplicationRenderingThread : public ApplicationThread
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationRenderingThread();
		~ApplicationRenderingThread();

	};

}