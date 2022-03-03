#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



/**
 *	Include SubRP
 */
#include <ING/Rendering/SubRP/Pass/Pass.h>



namespace ING {

	class Camera;



	namespace Rendering {

		namespace SubRP {

			class ING_API FirstPass : public SubRP::Pass
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				FirstPass	(std::string name);
				~FirstPass	();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual void CustomRender(IDeviceContext* context, Camera* camera, PassInput* input, PassOutput* output) override;

			};

		}

	}

}