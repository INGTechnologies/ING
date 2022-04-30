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
#include <ING/Rendering/SubRP/Pipeline/Pipeline.h>



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

				std::vector<SubRP::Pipeline*>					subPipelineVector;

				std::unordered_map<String, unsigned int>	subPipelineName2supPipeLineIndex;

				Mode				mode;

			public:
				IPass*				GetFirstPass					() { return firstPass; }
				IPass*				GetTargetFirstPass				() { return targetFirstPass; }
				void				SetFirstPass					(IPass* firstPass);

				IPass*				GetFinalPass					() { return finalPass; }
				IPass*				GetTargetFinalPass				() { return targetFinalPass; }
				void				SetFinalPass					(IPass* finalPass);

				SubRP::Pipeline*	GetSubPipeline					(unsigned int index)		{ return subPipelineVector[index]; }
				unsigned int		GetSubPipelineIndex				(const String& name)	{ return subPipelineName2supPipeLineIndex[name]; }
				SubRP::Pipeline*	GetSubPipeline					(const String& name)	{ return subPipelineVector[GetSubPipelineIndex(name)]; }
				unsigned int		GetSubPipelineIndex				(const char* name)			{ return GetSubPipelineIndex(String(name)); }
				SubRP::Pipeline*	GetSubPipeline					(const char* name)			{ return GetSubPipeline(String(name)); }

				Mode				GetMode							() { return mode; }
				void				SetMode							(Mode mode) { this->mode = mode; }



				/**
				 *	Methods
				 */
			public:
				virtual void SetupCamera		(IDeviceContext* context, Camera* camera) override;
				virtual void ClearRenderingData (Camera* camera) override;

				virtual bool Render				(IDeviceContext* context) override;

				virtual bool RenderSubPipelines	(IDeviceContext* context, Camera* camera, const Rendering::SubRP::PassInput& input, Rendering::SubRP::PassOutput& output);

				void		 AddSubPipeline		(SubRP::Pipeline* subPipeline);

				void		 AddSubPipeline		(SubRP::Pipeline* subPipeline, unsigned int index);

			};

		}

	}

}