
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



			isNeedGenerateSolution = true;

			String solutionGeneratorName = "VS2022";

			for (unsigned int i = 0; i < argv.size() - 1; ++i) {

				if (argv[i] == L"/Path:") {

					projectFilePath = argv[i + 1];

					++i;

				}
				else if (argv[i] == L"/GenerateSolution:") {

					if (argv[i + 1] == L"true") {

						isNeedGenerateSolution = true;

					}
					else isNeedGenerateSolution = false;

					++i;

				}
				else if (argv[i] == L"/IDE:") {

					solutionGeneratorName = ToString(argv[i + 1]);

					++i;

				}

			}

			if (projectFilePath == L"") {

				Release();

				return;
			}



			ReplaceAll(projectDirectoryPath, L"\\", L"/");

			projectDirectoryPath = Path::GetDirectoryPath(projectFilePath) + ToWString(L"\\");
			ReplaceAll(projectDirectoryPath, L"\\", L"/");

			name2PlaceholderValueMap["INGAbsProjectFile"] = projectFilePath;
			name2PlaceholderValueMap["INGAbsProjectDir"] = projectDirectoryPath;



			name2PlaceholderValueMap["SolutionGeneratorName"] = ToWString(solutionGeneratorName);
			name2PlaceholderValueMap["INGIDE"] = ToWString(solutionGeneratorName);

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

			if (projectJSON.find("engineProjectDir") == projectJSON.end())
				name2PlaceholderValueMap["INGEngineProjectDir"] = ToWString(L"$(SolutionDir)Source/Engine/");
			else
				name2PlaceholderValueMap["INGEngineProjectDir"] = Path::Normalize(ToWString(projectJSON["engineProjectDir"].get<std::string>()));



			if (projectJSON.find("buildRuntime") == projectJSON.end())
				name2PlaceholderValueMap["INGBuildRuntime"] = L"true";
			else {

				if (projectJSON["buildRuntime"].get<bool>()) {

					name2PlaceholderValueMap["INGBuildRuntime"] = L"true";

				}
				else {

					name2PlaceholderValueMap["INGBuildRuntime"] = L"false";

				}

			}

			if (projectJSON.find("buildPlugins") == projectJSON.end())
				name2PlaceholderValueMap["INGBuildPlugins"] = L"true";
			else {

				if (projectJSON["buildPlugins"].get<bool>()) {

					name2PlaceholderValueMap["INGBuildPlugins"] = L"true";

				}
				else {

					name2PlaceholderValueMap["INGBuildPlugins"] = L"false";

				}

			}

			if (projectJSON.find("buildEngine") == projectJSON.end())
				name2PlaceholderValueMap["INGBuildEngine"] = L"true";
			else {

				if (projectJSON["buildEngine"].get<bool>()) {

					name2PlaceholderValueMap["INGBuildEngine"] = L"true";

				}
				else {

					name2PlaceholderValueMap["INGBuildEngine"] = L"false";

				}

			}

			if (projectJSON.find("buildGame") == projectJSON.end())
				name2PlaceholderValueMap["INGBuildGame"] = L"true";
			else {

				if (projectJSON["buildGame"].get<bool>()) {

					name2PlaceholderValueMap["INGBuildGame"] = L"true";

				}
				else {

					name2PlaceholderValueMap["INGBuildGame"] = L"false";

				}

			}



			const std::vector<String> defaultPluginNameVector = {
			
				"ING.Standalone",
			
			};

			if (projectJSON.find("plugins") == projectJSON.end())
				pluginNameVector = defaultPluginNameVector;
			else
			{

				this->pluginNameVector = defaultPluginNameVector + projectJSON["plugins"].get<std::vector<std::string>>();

			}

			SetupPluginVector();



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
		void	ProjectBuilder::SetupPluginVector() {

			std::unordered_map<String, bool> pluginMap;

			for (unsigned int i = 0; i < pluginNameVector.size(); ++i) {

				pluginMap[pluginNameVector[i]] = true;

			}

			pluginNameVector.clear();

			for (auto item : pluginMap) {

				pluginNameVector.push_back(item.first);

			}

			for (unsigned int i = 0; i < pluginNameVector.size(); ++i) {

				WString pluginJSONFilePath = Path::Normalize(GetPlaceholder("INGAbsProjectDir") + ToWString(L"Plugins/") + ToWString(pluginNameVector[i]) + ToWString(L"/") + ToWString(pluginNameVector[i]) + ToWString(".iplugin"));

				if (std::filesystem::exists(pluginJSONFilePath)) {

					WString content = fileReader->Read(

						pluginJSONFilePath

					);

					JSON pluginJSON = ParseJSON(ToString(content));

					pluginJSON["name"] = pluginNameVector[i];

					if (pluginJSON.find("sourceDirName") == pluginJSON.end()) {

						pluginJSON["sourceDirName"] = ToString("Source/");

					}

					pluginJSONVector.push_back(pluginJSON);

					name2PluginJSONIndexMap[pluginNameVector[i]] = pluginJSONVector.size() - 1;

				}

			}

			SortPluginVector();

		}

		unsigned int ProjectBuilder::GetPluginLevel(const String& name) {

			unsigned int level = 1;
			
			JSON pluginJSON = GetPluginJSON(name);

			if (pluginJSON.find("dependencies") == pluginJSON.end()) {

				return level;
			}

			auto dependencies = pluginJSON["dependencies"].get<std::vector<std::string>>();

			for (auto item : dependencies) {

				unsigned int dependencyLevel = 1;

				if (name2PluginJSONIndexMap.find(item) != name2PluginJSONIndexMap.end()) {

					dependencyLevel = GetPluginLevel(item);

				}

				if (level < dependencyLevel + 1) {

					level = dependencyLevel + 1;

				}

			}

			return level;
		}

		void	ProjectBuilder::SortPluginVector() {

			/* Setup Name To Plugin Level Map */
			std::unordered_map<String, unsigned int> name2PluginLevelMap;

			for (auto item : name2PluginJSONIndexMap) {

				name2PluginLevelMap[item.first] = GetPluginLevel(item.first);

			}



			/* Sort */
			std::vector<JSON> pluginJSONVector = this->pluginJSONVector;

			for (unsigned int i = 0; i < pluginJSONVector.size(); ++i) {

				for (unsigned int j = 0; j < i; ++j) {

					if (
						name2PluginLevelMap[pluginJSONVector[i]["name"].get<std::string>()] < name2PluginLevelMap[pluginJSONVector[j]["name"].get<std::string>()]
					) {

						JSON mw = pluginJSONVector[i];
						pluginJSONVector[i] = pluginJSONVector[j];
						pluginJSONVector[j] = mw;

					}

				}

			}

			this->pluginJSONVector = pluginJSONVector;

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