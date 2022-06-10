
/**
 *	Include Header
 */
#include "ProjectGenerator.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Tools {

		/**
		 *	Constructors And Destructor
		 */
		IProjectGenerator::IProjectGenerator(ProjectBuilder* projectBuilder) :
			projectBuilder(projectBuilder)
		{



		}

		IProjectGenerator::~IProjectGenerator() {



		}



		/**
		 *	CreateInstance, Release Methods
		 */
		void	IProjectGenerator::Release() {

			delete this;
		}



		/**
		 *	Methods
		 */
		void	IProjectGenerator::Generate() {



		}
		
	}

}