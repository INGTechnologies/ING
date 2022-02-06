
/**
 *	Include Header
 */
#include "Rendering.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Thread Manager
 */
#include <ING/Application/Thread/Manager/Manager.h>



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationRenderingThread::ApplicationRenderingThread() :
		ApplicationThread([](ApplicationThread* thread) {
			
			Rendering::Engine::GetInstance()->FrameUpdate();
			
		})
	{



	}

	ApplicationRenderingThread::~ApplicationRenderingThread() {



	}

}
