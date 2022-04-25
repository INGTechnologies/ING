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
 *	Include EngineThread
 */
#include <ING\Engine/Thread/Thread.h>



namespace ING {

	class ING_API EngineRenderingThread : public EngineThread
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		EngineRenderingThread();
		~EngineRenderingThread();

	};

}