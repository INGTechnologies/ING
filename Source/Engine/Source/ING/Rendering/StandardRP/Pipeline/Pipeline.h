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



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class Device;

		class DeviceContext;

		class IPass;



		namespace StandardRP {

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
				IPass*	mainPass;
				IPass*	targetMainPass;

			public:
				IPass*	GetMainPass() { return mainPass; }

				IPass*	GetTargetMainPass() { return targetMainPass; }

				void	SetMainPass(IPass* mainPass);



				/**
				 *	Methods
				 */
			public:
				virtual void Render(DeviceContext* context) override;

			};

		}

	}

}