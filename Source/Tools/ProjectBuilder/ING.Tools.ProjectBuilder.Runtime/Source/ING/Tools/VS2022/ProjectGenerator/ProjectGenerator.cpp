
/**
 *	Include Header
 */
#include "ProjectGenerator.h"



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
			ProjectGenerator::ProjectGenerator(ProjectBuilder* projectBuilder) :
				IProjectGenerator(projectBuilder)
			{



			}

			ProjectGenerator::~ProjectGenerator() {



			}



			/**
			 *	Release Methods
			 */
			void	ProjectGenerator::Release() {

				IProjectGenerator::Release();
			}



			/**
			 *	Methods
			 */
			void	ProjectGenerator::Generate() {

				IProjectGenerator::Generate();

				if (GetProjectBuilder()->GetPlaceholder("INGBuildGame") == L"true")
					if (!std::filesystem::exists(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/Game/"))) {

						std::filesystem::create_directory(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + GetProjectBuilder()->GetPlaceholder("INGGameDirName"));

					}

				if (GetProjectBuilder()->GetPlaceholder("INGBuildEngine") == L"true") {

					if (!std::filesystem::exists(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString(L"/Engine/"))) {

						std::filesystem::create_directory(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + GetProjectBuilder()->GetPlaceholder("INGEngineDirName"));

					}

					WString targetEngineConfigFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + GetProjectBuilder()->GetPlaceholder("INGEngineDirName") + ToWString(L"/Config.ini"));

					if (!std::filesystem::exists(targetEngineConfigFilePath)) {

						GetProjectBuilder()
							->GetFileWriter()
							->Write(

								targetEngineConfigFilePath,

								GetProjectBuilder()
								->GetFileReader()
								->Read(L"./Templates/VS2022/Engine/Config.ini")

							);

					}

				}					
						


				if (GetProjectBuilder()->GetPlaceholder("INGBuildRuntime") == L"true")
					GenerateRuntimeProject(); 
						


				if (GetProjectBuilder()->GetPlaceholder("INGBuildPlugins") == L"true")
					GeneratePluginProjects();

			}

			void	ProjectGenerator::GenerateBuildEventsProject() {

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

			void	ProjectGenerator::GenerateRuntimeProject() {

				GenerateBuildEventsProject();

				WString targetVCXPROJFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString("/") + GetProjectBuilder()->GetPlaceholder("INGProjectName") + ToWString(L".Runtime/") + GetProjectBuilder()->GetPlaceholder("INGProjectName") + ToWString(L".Runtime_VS2022.vcxproj"));

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



				WString targetMainCPPFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString("/") + GetProjectBuilder()->GetPlaceholder("INGProjectName") + ToWString(L".Runtime/Source/main.cpp"));
				
				GetProjectBuilder()
					->GetFileWriter()
					->Write(

						targetMainCPPFilePath,

						GetProjectBuilder()
							->GetFileReader()
							->Read(L"./Templates/VS2022/Runtime/Source/main.cpp")
					
					);



			}

			void	ProjectGenerator::GeneratePluginProject(const String& name) {

				JSON pluginJSON = GetProjectBuilder()->GetPluginJSON(name);
				
				WString pluginWName = ToWString(pluginJSON["name"].get<std::string>());
				WString pluginWVarName = ToWString(pluginJSON["varname"].get<std::string>());

				GetProjectBuilder()->SetPlaceholder("INGPluginVarName", pluginWVarName);

				GetProjectBuilder()->SetPlaceholder("INGPluginName", pluginWName);
				


				std::vector<std::string> dependencies;
				
				if (pluginJSON.find("dependencies") != pluginJSON.end()) {

					dependencies = pluginJSON["dependencies"].get<std::vector<std::string>>();

				}



				WString pluginIncludePath = L";";

				for (auto item : dependencies) {

					/* If has plugin JSON, item is game plugin */
					if (GetProjectBuilder()->IsHasPluginJSON(item)) {

						pluginIncludePath += Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGProjectDir") + ToWString("/Plugins/") + ToWString(item) + ToWString("/Source/;"));

					}
					/* If not has plugin JSON, item is engine plugin */
					else {

						pluginIncludePath += Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGEngineProjectDir") + ToWString("/Plugins/") + ToWString(item) + ToWString("/Source/;"));

					}

				}

				GetProjectBuilder()->SetPlaceholder("INGPluginIncludePath", pluginIncludePath);


				WString pluginLibraryPath = L";";

				for (auto item : dependencies) {

					/* If has plugin JSON, item is game plugin */
					if (GetProjectBuilder()->IsHasPluginJSON(item)) {

						pluginLibraryPath += Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGEngineBinariesDir") + ToWString("/Plugins/") + ToWString(item) + ToWString("/;"));

					}
					/* If not has plugin JSON, item is engine plugin */
					else {

						pluginLibraryPath += Path::Normalize(ToWString("$(SolutionDir)Binaries/$(Platform)/$(Configuration)/") + GetProjectBuilder()->GetPlaceholder("INGIDE") + ToWString("/Engine/Plugins/") + ToWString(item) + ToWString("/;"));

					}

				}

				GetProjectBuilder()->SetPlaceholder("INGPluginLibraryPath", pluginLibraryPath);


				WString pluginDependenciesPath = L";";

				for (auto item : dependencies) {

					pluginDependenciesPath += ToWString(item) + ToWString(".lib;");

				}

				GetProjectBuilder()->SetPlaceholder("INGPluginDependencies", pluginDependenciesPath);



				WString targetVCXPROJFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString("/Plugins/") + pluginWName + ToWString(L"/") + pluginWName + ToWString(L"_VS2022.vcxproj"));

				if (std::filesystem::exists(targetVCXPROJFilePath)) {

					std::filesystem::remove(targetVCXPROJFilePath);

				}

				GetProjectBuilder()
					->GetFileWriter()
					->Write(

						targetVCXPROJFilePath,

						GetProjectBuilder()
						->GetFileReader()
						->Read(L"./Templates/VS2022/Plugin/Plugin_VS2022.vcxproj")

					);



				WString targetEntryPointHFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString("/Plugins/") + pluginWName + ToWString("/") + ToWString(pluginJSON["sourceDirName"].get<std::string>()) + ToWString(L"/EntryPoint/EntryPoint.h"));

				if (std::filesystem::exists(targetEntryPointHFilePath)) {

					std::filesystem::remove(targetEntryPointHFilePath);

				}

				GetProjectBuilder()
					->GetFileWriter()
					->Write(

						targetEntryPointHFilePath,

						GetProjectBuilder()
						->GetFileReader()
						->Read(L"./Templates/VS2022/Plugin/Source/EntryPoint/EntryPoint.h")

					);



				WString targetEntryPointCPPFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString("/Plugins/") + pluginWName + ToWString("/") + ToWString(pluginJSON["sourceDirName"].get<std::string>()) + ToWString(L"/EntryPoint/EntryPoint.cpp"));

				if (std::filesystem::exists(targetEntryPointCPPFilePath)) {

					std::filesystem::remove(targetEntryPointCPPFilePath);

				}

				GetProjectBuilder()
					->GetFileWriter()
					->Write(

						targetEntryPointCPPFilePath,

						GetProjectBuilder()
						->GetFileReader()
						->Read(L"./Templates/VS2022/Plugin/Source/EntryPoint/EntryPoint.cpp")

					);



				WString targetPluginHFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString("/Plugins/") + pluginWName + ToWString("/") + ToWString(pluginJSON["sourceDirName"].get<std::string>()) + ToWString(L"/Plugin/Plugin.h"));

				if (!std::filesystem::exists(targetPluginHFilePath)) {

					GetProjectBuilder()
						->GetFileWriter()
						->Write(

							targetPluginHFilePath,

							GetProjectBuilder()
							->GetFileReader()
							->Read(L"./Templates/VS2022/Plugin/Source/Plugin/Plugin.h")

						);

				}



				WString targetPluginCPPFilePath = Path::Normalize(GetProjectBuilder()->GetPlaceholder("INGAbsProjectDir") + ToWString("/Plugins/") + pluginWName + ToWString("/") + ToWString(pluginJSON["sourceDirName"].get<std::string>()) + ToWString(L"/Plugin/Plugin.cpp"));

				if (!std::filesystem::exists(targetPluginCPPFilePath)) {

					GetProjectBuilder()
						->GetFileWriter()
						->Write(

							targetPluginCPPFilePath,

							GetProjectBuilder()
							->GetFileReader()
							->Read(L"./Templates/VS2022/Plugin/Source/Plugin/Plugin.cpp")

						);

				}

			}

			void	ProjectGenerator::GeneratePluginProjects() {

				for (auto item : GetProjectBuilder()->GetPluginJSONVector()) {

					GeneratePluginProject(item["name"].get<std::string>());

				}

			}

		}
		
	}

}