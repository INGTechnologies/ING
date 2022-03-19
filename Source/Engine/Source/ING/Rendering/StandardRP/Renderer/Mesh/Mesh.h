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
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



namespace ING {

	class Camera;



	namespace Rendering {

		namespace StandardRP {

			class ING_API MeshRenderer
			{
				/**
				 *	Constructors And Destructor
				 */
			public:
				MeshRenderer();
				~MeshRenderer();

			};

		}

	}

}