#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;




/**
 *	Include SolutionGenerator
 */
#include <ING/Tools/SolutionGenerator/SolutionGenerator.h>



namespace ING {

	namespace Tools {

		namespace VS2022 {

			class SolutionGenerator : public ISolutionGenerator {

				/**
				 *	Constructors And Destructor
				 */
			public:
				SolutionGenerator(ProjectBuilder* projectBuilder);
				~SolutionGenerator();



				/**
				 *	Release Methods
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual void Generate() override;

				void GenerateBuildEventsProject();
				void GenerateRuntimeProject();

				void GeneratePluginProject(const String& name);
				void GeneratePluginProjects();

			};

		}
		
	}

}