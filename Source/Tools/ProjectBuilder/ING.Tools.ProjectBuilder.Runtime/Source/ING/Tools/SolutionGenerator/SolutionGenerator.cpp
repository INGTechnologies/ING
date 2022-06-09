
/**
 *	Include Header
 */
#include "SolutionGenerator.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Tools {

		/**
		 *	Constructors And Destructor
		 */
		ISolutionGenerator::ISolutionGenerator(ProjectBuilder* projectBuilder) :
			projectBuilder(projectBuilder)
		{



		}

		ISolutionGenerator::~ISolutionGenerator() {



		}



		/**
		 *	CreateInstance, Release Methods
		 */
		void	ISolutionGenerator::Release() {

			delete this;
		}



		/**
		 *	Methods
		 */
		void	ISolutionGenerator::Generate() {



		}
		
	}

}