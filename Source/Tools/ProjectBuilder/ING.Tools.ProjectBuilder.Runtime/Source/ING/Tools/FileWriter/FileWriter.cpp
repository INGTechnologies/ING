
/**
 *	Include Header
 */
#include "FileWriter.h"



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
		IFileWriter::IFileWriter(ProjectBuilder* projectBuilder) :
			projectBuilder(projectBuilder)
		{



		}

		IFileWriter::~IFileWriter() {



		}



		/**
		 *	Release Methods
		 */
		void	IFileWriter::Release() {

			delete this;
		}



		/**
		 *	Methods
		 */
		void	IFileWriter::Write(const WString& path, const WString& content) {



		}
		
	}

}