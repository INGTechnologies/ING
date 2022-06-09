
/**
 *	Include Header
 */
#include "FileWriter.h"



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
			FileWriter::FileWriter(ProjectBuilder* projectBuilder) :
				IFileWriter(projectBuilder)
			{



			}

			FileWriter::~FileWriter() {



			}



			/**
			 *	CreateInstance, Release Methods
			 */
			void	FileWriter::Release() {

				IFileWriter::Release();

			}



			/**
			 *	Methods
			 */
			void	FileWriter::Write(const WString& path, const WString& content) {

				WString parsedContent = content;

				for (auto item : GetProjectBuilder()->GetName2PlaceholderValueMap()) {

					ReplaceAll(parsedContent, ToWString(L"$(") + ToWString(item.first) + ToWString(L")"), item.second);

				}



				std::wfstream fileStream;



				if (!std::filesystem::exists(path)) {

					std::filesystem::create_directories(std::filesystem::path(path).parent_path());

					std::ofstream ofs(path);
					ofs.close();

				}



				/* Open File */
				fileStream.open(path.c_str());



				fileStream.write(parsedContent.c_str(), parsedContent.length());



				/* Close File */
				fileStream.close();

			}

		}
		
	}

}