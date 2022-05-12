#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



namespace ING {

	class Camera;



	namespace Rendering {

		namespace StandardRP {

			class ING_API SkyPass : public IPass
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				SkyPass	(const String& name);
				~SkyPass	();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual bool Render(IDeviceContext* context, Camera* camera) override;

			};

		}

	}

}