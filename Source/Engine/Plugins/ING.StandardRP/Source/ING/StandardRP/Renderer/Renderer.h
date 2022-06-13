#pragma once

/**
 *	Include StandardRP Plugin
 */
#include <ING\StandardRP\Plugin\Plugin.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Rendering Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



namespace ING {

	namespace StandardRP {

		class PLUGIN_API(ING_STANDARDRP) C_Renderer : public Rendering::C_Renderer
		{

			ING_REFLECT_CLASS(C_Renderer, Rendering::C_Renderer)



			/**
			 *	Constructor
			 */
		protected:
			void Constructor();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;

		};

	}

}