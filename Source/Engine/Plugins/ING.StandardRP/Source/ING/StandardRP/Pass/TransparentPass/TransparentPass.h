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
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



namespace ING {

	namespace StandardRP {

		class PLUGIN_API(ING_STANDARDRP) C_TransparentPass : public Rendering::C_Pass
		{

			ING_REFLECT_CLASS(C_TransparentPass, Rendering::C_Pass)



			/**
			 *	Constructor
			 */
		protected:
			void Constructor(const String& name);



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;



			/**
			 *	Methods
			 */
		public:
			virtual bool Render(Rendering::IDeviceContext * context, C_Camera * camera) override;

		};

	}

}