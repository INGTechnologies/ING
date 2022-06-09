
/**
 *	Include Header
 */
#include "SolutionGenerator.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include ProjectBuilder
 */
#include <ING/Tools/ProjectBuilder/ProjectBuilder.h>



namespace ING {

	namespace Tools {

		namespace VS2022 {

			/**
			 *	Constructors And Destructor
			 */
			SolutionGenerator::SolutionGenerator(ProjectBuilder* projectBuilder) :
				ISolutionGenerator(projectBuilder)
			{



			}

			SolutionGenerator::~SolutionGenerator() {



			}



			/**
			 *	Release Methods
			 */
			void	SolutionGenerator::Release() {

				ISolutionGenerator::Release();
			}



			/**
			 *	Methods
			 */
			void	SolutionGenerator::Generate() {

				ISolutionGenerator::Generate();

				

			}

		}
		
	}

}