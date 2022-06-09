
/**
 *	Include Header
 */
#include "FileReader.h"



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
		IFileReader::IFileReader(ProjectBuilder* projectBuilder) :
			projectBuilder(projectBuilder)
		{



		}

		IFileReader::~IFileReader() {



		}



		/**
		 *	Release Methods
		 */
		void	IFileReader::Release() {

			delete this;
		}



		/**
		 *	Methods
		 */
		WString	IFileReader::Read(const WString& path) {



			return L"";

		}
		
	}

}