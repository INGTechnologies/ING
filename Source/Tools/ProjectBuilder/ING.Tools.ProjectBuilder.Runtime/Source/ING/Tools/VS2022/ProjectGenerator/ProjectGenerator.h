#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;




/**
 *	Include ProjectGenerator
 */
#include <ING/Tools/ProjectGenerator/ProjectGenerator.h>



namespace ING {

	namespace Tools {

		namespace VS2022 {

			class ProjectGenerator : public IProjectGenerator {

				/**
				 *	Constructors And Destructor
				 */
			public:
				ProjectGenerator(ProjectBuilder* projectBuilder);
				~ProjectGenerator();



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