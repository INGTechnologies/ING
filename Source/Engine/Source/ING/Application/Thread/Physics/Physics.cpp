
/**
 *	Include Header
 */
#include "Physics.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Application Thread Manager
 */
#include <ING/Application/Thread/Manager/Manager.h>



/**
 *	Include Rendering Engine
 */
#include <ING/Rendering/Engine/Engine.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ApplicationPhysicsThread::ApplicationPhysicsThread() :
		ApplicationThread([](ApplicationThread* thread) {
			
			Rendering::Engine::GetInstance()->FrameUpdate();
			
		})
	{



	}

	ApplicationPhysicsThread::~ApplicationPhysicsThread() {



	}

}
