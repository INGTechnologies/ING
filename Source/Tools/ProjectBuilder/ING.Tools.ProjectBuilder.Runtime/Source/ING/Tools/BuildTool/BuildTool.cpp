
/**
 *	Include Header
 */
#include "BuildTool.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



#include <fstream>
#include <wchar.h>



/**
 *	Include ProjectBuilder
 */
#include <ING/Tools/ProjectBuilder/ProjectBuilder.h>



namespace ING {

	namespace Tools {

		/**
		 *	Constructors And Destructor
		 */
		IBuildTool::IBuildTool(ProjectBuilder* projectBuilder) :
			projectBuilder(projectBuilder)
		{



		}

		IBuildTool::~IBuildTool() {



		}



		/**
		 *	Release Methods
		 */
		void	IBuildTool::Release() {

			delete this;
		}



		/**
		 *	Methods
		 */
		void	IBuildTool::Build() {



		}
		
	}

}