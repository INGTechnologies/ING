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

			class ING_API TransparentPass : public IPass
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				TransparentPass	(const String& name);
				~TransparentPass	();



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