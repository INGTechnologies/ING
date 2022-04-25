
/**
 *	Include Header
 */
#include "Rendering.h"



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Engine Thread Manager
 */
#include <ING/Engine/Thread/Manager/Manager.h>



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	EngineRenderingThread::EngineRenderingThread() :
		EngineThread([](EngineThread* thread) {
			
			Rendering::Engine::GetInstance()->FrameUpdate();
			
		})
	{



	}

	EngineRenderingThread::~EngineRenderingThread() {



	}

}
