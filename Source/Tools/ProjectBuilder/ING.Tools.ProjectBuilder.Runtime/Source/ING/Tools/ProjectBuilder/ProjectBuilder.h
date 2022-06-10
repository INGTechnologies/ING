
/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>
using namespace ING::Utils;



namespace ING {

	namespace Tools {

		class ISolutionGenerator;
		class IFileReader;
		class IFileWriter;
		class IBuildTool;



		class ProjectBuilder : public Singleton<ProjectBuilder> {

			/**
			 *	Friend Classes
			 */
		public:
			friend class Singleton<ProjectBuilder>;



			/**
			 *	Constructors And Destructor
			 */
		protected:
			ProjectBuilder	();

		public:
			ProjectBuilder	(const std::vector<WString>& argv);

		public:
			~ProjectBuilder	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void	Release();



			/**
			 *	Properties
			 */
		private:
			std::vector<WString> argv;

			WString			projectFilePath;
			WString			projectDirectoryPath;

			bool			isNeedGenerateSolution;

			ISolutionGenerator* solutionGenerator;

			IBuildTool*		buildTool;

			std::unordered_map<String, WString> name2PlaceholderValueMap;

			IFileReader*	fileReader;
			IFileWriter*	fileWriter;

			WString			projectFileContent;

			JSON			projectJSON;

			std::vector<String>	pluginNameVector;
			std::vector<JSON>	pluginJSONVector;

			std::unordered_map<String, unsigned int> name2PluginJSONIndexMap;

			String			buildConfig;

		public:
			const std::vector<WString>& GetArgv () { return argv; }

			const WString&	GetProjectFilePath () { return projectFilePath; }
			const WString&	GetProjectDirectoryPath() { return projectDirectoryPath; }

			bool			IsNeedGenerateSolution () { return isNeedGenerateSolution; }

			ISolutionGenerator* GetSolutionGenerator () { return solutionGenerator; }

			IBuildTool*		GetBuildTool () { return buildTool; }

			const std::unordered_map<String, WString>& GetName2PlaceholderValueMap() { return name2PlaceholderValueMap; }

			const WString&	GetPlaceholder(const String& name) { return name2PlaceholderValueMap.find(name)->second; }
			void			SetPlaceholder(const String& name, const WString& value) { name2PlaceholderValueMap[name] = value; }

			IFileReader*	GetFileReader () { return fileReader; }
			IFileWriter*	GetFileWriter () { return fileWriter; }

			const WString&	GetProjectFileContent () { return projectFileContent; }

			const JSON&		GetProjectJSON () { return projectJSON; }

			const std::vector<String>&	GetPluginNameVector () { return pluginNameVector; }
			const std::vector<JSON>&	GetPluginJSONVector () { return pluginJSONVector; }

			const JSON&		GetPluginJSON	(const String& name) { return pluginJSONVector[name2PluginJSONIndexMap[name]]; }
			bool			IsHasPluginJSON (const String& name) { return name2PluginJSONIndexMap.find(name) != name2PluginJSONIndexMap.end(); }

			const std::unordered_map<String, unsigned int>& GetName2PluginJSONIndexMap () { return name2PluginJSONIndexMap; }

			const String&	GetBuildConfig () { return buildConfig; }



			/**
			 *	Methods
			 */
		public:
			void SetupPluginVector();

		private:
			unsigned int GetPluginLevel(const String& name);

		public:
			void SortPluginVector();
			
			void GenerateSolution();
			void Build();

		};
		
	}

}