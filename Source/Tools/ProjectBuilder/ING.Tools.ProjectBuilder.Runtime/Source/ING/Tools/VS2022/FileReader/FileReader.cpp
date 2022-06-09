
/**
 *	Include Header
 */
#include "FileReader.h"



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
			FileReader::FileReader(ProjectBuilder* projectBuilder) :
				IFileReader(projectBuilder)
			{



			}

			FileReader::~FileReader() {



			}



			/**
			 *	CreateInstance, Release Methods
			 */
			void	FileReader::Release() {

				IFileReader::Release();

			}



			/**
			 *	Methods
			 */
			WString	FileReader::Read(const WString& path) {

				WString rawContent = L"";

				std::wfstream fileStream;

				std::streampos fileSize = 0;



				/* Open File */
				fileStream.open(path.c_str());



				/* Get File Size */
				fileStream.seekg(0, std::wios::end);

				fileSize = fileStream.tellg();

				fileStream.seekg(0, std::wios::beg);



				/* Read File */
				rawContent.resize(fileSize);

				fileStream.read((wchar_t*)rawContent.c_str(), fileSize);



				/* Close File */
				fileStream.close();



				WString result = rawContent;

				for (auto item : GetProjectBuilder()->GetName2PlaceholderValueMap()) {

					ReplaceAll(result, ToWString(L"$(") + ToWString(item.first) + ToWString(L")"), item.second);

				}

				return result;

			}

		}
		
	}

}