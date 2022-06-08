
/**
 *	Include Header
 */
#include "ProjectBuilder.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace Tools {

		/**
		 *	Constructors And Destructor
		 */
		ProjectBuilder::ProjectBuilder() {



		}

		ProjectBuilder::ProjectBuilder(const std::vector<WString>& argv) :
			argv(argv)
		{

			if (argv.size() < 3) {

				Release();

				return;
			}

			projectFilePath = argv[1];
			projectDirectoryPath = Path::GetDirectoryPath(projectFilePath) + ToWString(L"\\");

			configurationName = ToString(argv[2]);

		}

		ProjectBuilder::~ProjectBuilder() {



		}



		/**
		 *	CreateInstance, Release Methods
		 */
		void	ProjectBuilder::Release() {

			delete this;
		}



		/**
		 *	Methods
		 */
		void	ProjectBuilder::Build() {



		}
		
	}

}