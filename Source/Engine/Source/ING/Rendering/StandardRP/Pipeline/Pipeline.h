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
				IPass*				firstPass;
				IPass*				targetFirstPass;

				IPass*				finalPass;
				IPass*				targetFinalPass;

				std::vector<SubRP::Pipeline*>					subPipelineVector;

				std::unordered_map<std::string, unsigned int>	subPipelineName2supPipeLineIndex;

			public:
				IPass*				GetFirstPass					() { return firstPass; }
				IPass*				GetTargetFirstPass				() { return targetFirstPass; }
				void				SetFirstPass					(IPass* firstPass);

				IPass*				GetFinalPass					() { return finalPass; }
				IPass*				GetTargetFinalPass				() { return targetFinalPass; }
				void				SetFinalPass					(IPass* finalPass);

				SubRP::Pipeline*	GetSubPipeline					(unsigned int index)		{ return subPipelineVector[index]; }
				unsigned int		GetSubPipelineIndex				(const std::string& name)	{ return subPipelineName2supPipeLineIndex[name]; }
				SubRP::Pipeline*	GetSubPipeline					(const std::string& name)	{ return subPipelineVector[GetSubPipelineIndex(name)]; }
				unsigned int		GetSubPipelineIndex				(const char* name)			{ return GetSubPipelineIndex(String(name)); }
				SubRP::Pipeline*	GetSubPipeline					(const char* name)			{ return GetSubPipeline(String(name)); }



				/**
				 *	Methods
				 */
			public:
				virtual bool Render				(IDeviceContext* context) override;

				virtual bool RenderSubPipelines	(IDeviceContext* context, Camera* camera, const Rendering::SubRP::PassInput& input, Rendering::SubRP::PassOutput& output);

				void		 AddSubPipeline		(SubRP::Pipeline* subPipeline);

				void		 AddSubPipeline		(SubRP::Pipeline* subPipeline, unsigned int index);

			};

		}

	}

}