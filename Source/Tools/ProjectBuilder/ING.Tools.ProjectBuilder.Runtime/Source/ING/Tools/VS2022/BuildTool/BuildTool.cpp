
/**
 *	Include Header
 */
#include "BuildTool.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



#include <fstream>
#include <sstream>



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
			BuildTool::BuildTool(ProjectBuilder* projectBuilder) :
				IBuildTool(projectBuilder)
			{



			}

			BuildTool::~BuildTool() {



			}



			/**
			 *	CreateInstance, Release Methods
			 */
			void	BuildTool::Release() {

				IBuildTool::Release();

			}



			/**
			 *	Methods
			 */
			void	BuildTool::Build() {



			}

		}
		
	}

}