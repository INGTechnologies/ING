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

			struct MainPassInput {



			};

			struct MainPassOutput {



			};



			class ING_API MainPass : public Pass<MainPassInput, MainPassOutput>
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				MainPass	(std::string name);
				~MainPass	();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual void CustomRender(DeviceContext* context, Camera* camera, MainPassInput* input, MainPassOutput* output) override;

			};

		}

	}

}