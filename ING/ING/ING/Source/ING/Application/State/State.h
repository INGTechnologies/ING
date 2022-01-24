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

	enum ApplicationState {

		NONE_APPLICATION_STATE,

		CREATED_APPLICATION_STATE,
		
		INITIALIZED_APPLICATION_STATE,
		
		RUNNING_APPLICATION_STATE,

		CLOSED_APPLICATION_STATE

	};

}