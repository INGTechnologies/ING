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
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



namespace ING {

	class Camera;



	namespace Rendering {

		namespace SubRP {

			using Pass			= Rendering::Pass<VirtualObject, VirtualObject>;
			using PassInput		= VirtualObject;
			using PassOutput	= VirtualObject;

		}

	}

}