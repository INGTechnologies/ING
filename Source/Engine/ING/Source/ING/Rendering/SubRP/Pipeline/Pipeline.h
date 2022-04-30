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
				std::vector<IPass*>		passVector;

				std::unordered_map<String, unsigned int>	passName2PassIndex;

			public:
				std::vector<IPass*>&	GetPassVector		() { return passVector; }



				/**
				 *	Methods
				 */
			public:
				virtual bool Render		(IDeviceContext* context) override;

				virtual bool SubRender	(IDeviceContext* context, Camera* camera, const PassInput& input, PassOutput& output);

				unsigned int GetPassIndex	(const String& name);

				unsigned int AddPass	(IPass* pass); 
				void		 AddPass	(IPass* pass, unsigned int index);
				IPass*		 GetPass	(unsigned int index);
				IPass*		 GetPass	(const String& name);
				void		 RemovePass	(unsigned int index);

			};

		}

	}

}