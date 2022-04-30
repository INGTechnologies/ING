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
 *	Include SubRP Pipeline
 */
#include <ING/Rendering/StandardRP/Mode/Mode.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;



		namespace StandardRP {

			class ING_API Pipeline : public IPipeline
			{

				/**
				 *	Constructors And Destructor
				 */
			public:
				Pipeline(String name);
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
				IPass*				firstPass;
				IPass*				targetFirstPass;

				IPass*				finalPass;
				IPass*				targetFinalPass;

				Mode				mode;

			public:
				IPass*				GetFirstPass					() { return firstPass; }
				IPass*				GetTargetFirstPass				() { return targetFirstPass; }
				void				SetFirstPass					(IPass* firstPass);

				IPass*				GetFinalPass					() { return finalPass; }
				IPass*				GetTargetFinalPass				() { return targetFinalPass; }
				void				SetFinalPass					(IPass* finalPass);

				Mode				GetMode							() { return mode; }
				void				SetMode							(Mode mode) { this->mode = mode; }



				/**
				 *	Methods
				 */
			public:
				virtual void SetupCamera		(IDeviceContext* context, Camera* camera) override;
				virtual void ClearCameraData	(Camera* camera) override;

				virtual bool Render				(IDeviceContext* context) override;

			};

		}

	}

}