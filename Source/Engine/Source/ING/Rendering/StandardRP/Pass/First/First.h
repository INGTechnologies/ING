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

			struct FirstPassInput {



			};

			struct FirstPassOutput {



			};



			class ING_API FirstPass : public Pass<FirstPassInput, FirstPassOutput>
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
				virtual void CustomRender(IDeviceContext* context, Camera* camera, FirstPassInput* input, FirstPassOutput* output) override;

			};

		}

	}

}