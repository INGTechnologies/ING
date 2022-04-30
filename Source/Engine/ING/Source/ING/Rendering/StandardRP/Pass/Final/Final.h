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

			struct FinalPassInput {



			};

			struct FinalPassOutput {



			};



			class ING_API FinalPass : public Pass<FinalPassInput, FinalPassOutput>
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				FinalPass	(String name);
				~FinalPass	();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual bool CustomRender(IDeviceContext* context, Camera* camera, const FinalPassInput& input, FinalPassOutput& output) override;

			};

		}

	}

}