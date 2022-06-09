
/**
 *	Include Header
 */
#include "ProjectBuilder.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include VS2022 SolutionGenerator
 */
#include <ING/Tools/VS2022/SolutionGenerator/SolutionGenerator.h>



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

		/**
		 *	Constructors And Destructor
		 */
		ProjectBuilder::ProjectBuilder() :
			solutionGenerator(0),
			fileReader(0),
			fileWriter(0)
		{



		}

		ProjectBuilder::ProjectBuilder(const std::vector<WString>& argv) :
			ProjectBuilder()
		{

			this->argv = argv;

			if (argv.size() < 2) {

				Release();

				return;
			}



			projectFilePath = argv[1];
			ReplaceAll(projectDirectoryPath, L"\\", L"/");

			projectDirectoryPath = Path::GetDirectoryPath(projectFilePath) + ToWString(L"\\");
			ReplaceAll(projectDirectoryPath, L"\\", L"/");

			name2PlaceholderValueMap["INGAbsProjectFile"] = projectFilePath;
			name2PlaceholderValueMap["INGAbsProjectDir"] = projectDirectoryPath;



			isNeedGenerateSolution = true;

			if (argv.size() > 2) {

				isNeedGenerateSolution = (argv[2] == ToWString("true"));

			}

			String solutionGeneratorName = "VS2022";

			if (argv.size() > 3) {

				solutionGeneratorName = ToString(argv[3]);

			}

			name2PlaceholderValueMap["SolutionGeneratorName"] = ToWString(solutionGeneratorName);

			if (solutionGeneratorName == "VS2022") {

				fileReader = new VS2022::FileReader(this);

			}

			if (solutionGeneratorName == "VS2022") {

				fileWriter = new VS2022::FileWriter(this);

			}



			if (
				fileReader == 0
				|| fileWriter == 0
			) {

				Release();

				return;

			}

			projectFileContent = fileReader->Read(projectFilePath);



			projectJSON = ParseJSON(projectFileContent);



			if (projectJSON.find("name") == projectJSON.end())
				name2PlaceholderValueMap["INGProjectName"] = ToWString(L"Untitled");
			else
				name2PlaceholderValueMap["INGProjectName"] = ToWString(projectJSON["name"].get<std::string>());

			if (projectJSON.find("mode") == projectJSON.end())
				name2PlaceholderValueMap["INGMode"] = ToWString(L"ING.Standalone");
			else
				name2PlaceholderValueMap["INGMode"] = ToWString(projectJSON["mode"].get<std::string>());

			if (projectJSON.find("projectDir") == projectJSON.end())
				name2PlaceholderValueMap["INGProjectDir"] = ToWString(L"$(Solution)Source/Games/") + GetPlaceholder("INGProjectName");
			else
				name2PlaceholderValueMap["INGProjectDir"] = ToWString(projectJSON["projectDir"].get<std::string>());

			name2PlaceholderValueMap["INGProjectFile"] = Path::Normalize(GetPlaceholder("INGProjectDir") + ToWString(L"/") + GetPlaceholder("INGProjectName") + ToWString(L".iproject"));

			if (projectJSON.find("engineDirName") == projectJSON.end())
				name2PlaceholderValueMap["INGEngineDir"] = Path::Normalize(GetPlaceholder("INGProjectDir") + ToWString(L"/Engine/"));
			else
				name2PlaceholderValueMap["INGEngineDir"] = Path::Normalize(GetPlaceholder("INGProjectDir") + ToWString(L"/") + ToWString(projectJSON["engineDirName"].get<std::string>()) + ToWString(L"/"));

			if (projectJSON.find("gameDirName") == projectJSON.end())
				name2PlaceholderValueMap["INGGameDir"] = Path::Normalize(GetPlaceholder("INGProjectDir") + ToWString(L"/Game/"));
			else
				name2PlaceholderValueMap["INGGameDir"] = Path::Normalize(GetPlaceholder("INGProjectDir") + ToWString(L"/") + ToWString(projectJSON["gameDirName"].get<std::string>()) + ToWString(L"/"));

			if (projectJSON.find("binariesDirName") == projectJSON.end())
				name2PlaceholderValueMap["INGBinariesDir"] = Path::Normalize(GetPlaceholder("INGProjectDir") + ToWString(L"/Binaries/"));
			else
				name2PlaceholderValueMap["INGBinariesDir"] = Path::Normalize(GetPlaceholder("INGProjectDir") + ToWString(projectJSON["binariesDirName"].get<std::string>()) + ToWString(L"/"));

			if (projectJSON.find("engineDirName") == projectJSON.end())
				name2PlaceholderValueMap["INGEngineBinariesDir"] = Path::Normalize(GetPlaceholder("INGBinariesDir") + ToWString(L"/Engine/"));
			else
				name2PlaceholderValueMap["INGEngineBinariesDir"] = Path::Normalize(GetPlaceholder("INGBinariesDir") + ToWString(L"/") + ToWString(projectJSON["engineDirName"].get<std::string>()) + ToWString(L"/"));

			if (projectJSON.find("gameDirName") == projectJSON.end())
				name2PlaceholderValueMap["INGGameBinariesDir"] = Path::Normalize(GetPlaceholder("INGBinariesDir") + ToWString(L"/Game/"));
			else
				name2PlaceholderValueMap["INGGameBinariesDir"] = Path::Normalize(GetPlaceholder("INGBinariesDir") + ToWString(L"/") + ToWString(projectJSON["gameDirName"].get<std::string>()) + ToWString(L"/"));



			const std::vector<String> defaultGamePluginNameVector = {
			
				"ING.Standalone",
			
			};

			if (projectJSON.find("gamePlugins") == projectJSON.end())
				gamePluginNameVector = defaultGamePluginNameVector;
			else
			{

				this->gamePluginNameVector = defaultGamePluginNameVector + projectJSON["gamePlugins"].get<std::vector<std::string>>();

			}

			gamePluginJSONVector.resize(gamePluginNameVector.size());

			SetupGamePluginVector();



			if (solutionGeneratorName == "VS2022") {

				solutionGenerator = new VS2022::SolutionGenerator(this);

			}

			if (
				solutionGenerator == 0
			) {

				Release();

				return;

			}

		}

		ProjectBuilder::~ProjectBuilder() {



		}



		/**
		 *	Release Methods
		 */
		void	ProjectBuilder::Release() {

			if (solutionGenerator == 0) {

				solutionGenerator->Release();

			}

			if (fileReader == 0) {

				fileReader->Release();

			}

			delete this;
		}



		/**
		 *	Methods
		 */
		void	ProjectBuilder::SetupGamePluginVector() {

			for (unsigned int i = 0; i < gamePluginNameVector.size(); ++i) {

				WString gamePluginJSONFilePath = Path::Normalize(GetPlaceholder("INGAbsProjectDir") + ToWString(L"GamePlugins/") + ToWString(gamePluginNameVector[i]) + ToWString(L"/") + ToWString(gamePluginNameVector[i]) + ToWString(".igamePlugin"));

				if (std::filesystem::exists(gamePluginJSONFilePath)) {

					WString content = fileReader->Read(

						gamePluginJSONFilePath

					);

					gamePluginJSONVector[i] = ParseJSON(ToString(content));

				}

			}

			SortGamePluginList();

		}

		void	ProjectBuilder::SortGamePluginList() {



		}

		void	ProjectBuilder::GenerateSolution() {

			solutionGenerator->Generate();

		}

		void	ProjectBuilder::Build() {

			if (isNeedGenerateSolution) {

				GenerateSolution();

			}

		}
		
	}

}