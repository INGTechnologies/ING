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
 *	Include Rendering Pipeline
 */
#include <ING/Rendering/Pipeline/Pipeline.h>



/**
 *	Include SubRP Pass
 */
#include <ING/Rendering/SubRP/Pass/Pass.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;



		namespace SubRP {

			class ING_API Pipeline : public IPipeline
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Pipeline(std::string name);
				~Pipeline();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				std::vector<IPass*>		passVector;

			public:
				std::vector<IPass*>&	GetPassVector		() { return passVector; }



				/**
				 *	Methods
				 */
			public:
				virtual void Render		(IDeviceContext* context) override;

				virtual void SubRender	(IDeviceContext* context, Camera* camera, PassInput* input, PassOutput* output);

				unsigned int AddPass	(IPass* pass);
				void		 RemovePass	(unsigned int index);

			};

		}

	}

}