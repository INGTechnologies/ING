
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

				std::wifstream fileStream(path);

				WString result = WString(
					std::istreambuf_iterator<wchar_t>(fileStream),
					std::istreambuf_iterator<wchar_t>()
				);

				fileStream.close();

				for (auto item : GetProjectBuilder()->GetName2PlaceholderValueMap()) {

					ReplaceAll(result, ToWString(L"$(") + ToWString(item.first) + ToWString(L")"), item.second);

				}

				return result;

			}

		}
		
	}

}