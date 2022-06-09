
/**
 *	Include Header
 */
#include "SolutionGenerator.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include ProjectBuilder
 */
#include <ING/Tools/ProjectBuilder/ProjectBuilder.h>



/**
 *	Include VS2022 FileReader
 */
#include <ING/Tools/VS2022/FileReader/FileReader.h>



/**
 *	Include VS2022 FileWriter
 */
#include <ING/Tools/VS2022/FileWriter/FileWriter.h>



namespace ING {

	namespace Tools {

		namespace VS2022 {

			/**
			 *	Constructors And Destructor
			 */
			SolutionGenerator::SolutionGenerator(ProjectBuilder* projectBuilder) :
				ISolutionGenerator(projectBuilder)
			{



			}

			SolutionGenerator::~SolutionGenerator() {



			}



			/**
			 *	Release Methods
			 */
			void	SolutionGenerator::Release() {

				ISolutionGenerator::Release();
			}



			/**
			 *	Methods
			 */
			void	SolutionGenerator::Generate() {

				ISolutionGenerator::Generate();

				if (!std::filesystem::exists(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/Engine/"))) {

					std::filesystem::create_directory(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/Engine/"));

				}

				if (!std::filesystem::exists(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/Game/"))) {

					std::filesystem::create_directory(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/Game/"));

				}

				WString targetEngineConfigFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/Engine/Config.ini"));

				GetProjectBuilder()
					->GetFileWriter()
					->Write(

						targetEngineConfigFilePath,

						GetProjectBuilder()
						->GetFileReader()
						->Read(L"./Templates/VS2022/Engine/Config.ini")

					);

				GenerateBuildEventsProject();

				GenerateRuntimeProject();

			}

			void	SolutionGenerator::GenerateBuildEventsProject() {

				WString targetBuildEventsProjectDir = GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/BuildEvents/");

				if (std::filesystem::exists(targetBuildEventsProjectDir)) {

					std::filesystem::remove_all(targetBuildEventsProjectDir);

				}

				std::filesystem::copy(
				
					L"./Templates/VS2022/BuildEvents/",

					Path::Normalize(targetBuildEventsProjectDir)

				);

				WString targetCSPROJFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/BuildEvents/BuildEvents_VS2022.csproj"));

				GetProjectBuilder()
					->GetFileWriter()
					->Write(

						targetCSPROJFilePath,

						GetProjectBuilder()
						->GetFileReader()
						->Read(L"./Templates/VS2022/BuildEvents/BuildEvents_VS2022.csproj")

					);

			}

			void	SolutionGenerator::GenerateRuntimeProject() {

				WString targetVCXPROJFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/Runtime/") + GetProjectBuilder()->GetPlaceholder("INGProjectName") + ToWString(L".Runtime_VS2022.vcxproj"));

				if (std::filesystem::exists(targetVCXPROJFilePath)) {

					std::filesystem::remove(targetVCXPROJFilePath);

				}

				GetProjectBuilder()
					->GetFileWriter()
					->Write(

						targetVCXPROJFilePath,

						GetProjectBuilder()
							->GetFileReader()
							->Read(L"./Templates/VS2022/Runtime/Runtime_VS2022.vcxproj")

					);



				WString targetMainCPPFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/Runtime/Source/main.cpp"));
				
				GetProjectBuilder()
					->GetFileWriter()
					->Write(

						targetMainCPPFilePath,

						GetProjectBuilder()
							->GetFileReader()
							->Read(L"./Templates/VS2022/Runtime/Source/main.cpp")
					
					);



			}

		}
		
	}

}