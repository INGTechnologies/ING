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
 *	Include Rendering Pipeline
 */
#include <ING/Rendering/Pipeline/Pipeline.h>



namespace ING {

	namespace StandardRP {

		class PLUGIN_API(ING_STANDARDRP) C_Pipeline : public Rendering::C_Pipeline
		{

			ING_REFLECT_CLASS(C_Pipeline, Rendering::C_Pipeline)



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
			virtual void SetupCamera		(Rendering::IDeviceContext* context, C_Camera* camera);
			virtual void ClearCameraData	(C_Camera* camera);

			virtual bool Render				(Rendering::IDeviceContext* context);

		};

	}

}